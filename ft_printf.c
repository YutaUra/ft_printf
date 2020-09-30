/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yura <yura@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 20:40:41 by yura              #+#    #+#             */
/*   Updated: 2020/09/30 09:01:15 by yura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

static void	initialize_flag(t_flag *flag);
static void print_flag(t_flag *flag);
static int	parse_format(const char** src, va_list *args, t_flag *flag);
static void parse_precision(const char** src, va_list *args, t_flag *flag);
static void parse_min_width(const char** src, va_list *args, t_flag *flag);
static int print_value(va_list *args, t_flag *flag);
static int print_c(va_list *args, t_flag *flag);
static int print_s(va_list *args, t_flag *flag);
static int print_di(va_list *args, t_flag *flag);
static int print_u(va_list *args, t_flag *flag);
static int print_pxX(va_list *args, t_flag *flag);
static int print_modulo(t_flag *flag);

static int print_string(char *str, t_flag *flag);
static void show_flag(t_flag *flag);
// static int	parse_format(const char** src, va_list *args, t_flag *flag, int *cnt);
// static int	parse_format_str(const char *src, va_list *args, t_flag *flag, int *cnt);

/*
**  ft_printf
**
**    format configuration
**      %[flag]?[* minimum field width][. precision][length modifier][conversions]
**
**      flag
**        - left alignment
**        0 zero padding
**        .
**        *
**
**      length modifier (not need)
**        hh
**        h
**        l
**        ll
**        L
**        j
**        z
**        t
**
**      conversions
**        c int to unsigned char
**        s string
**        p pointer
**        d int with base 10
**        i int with base 10
**        u unsigned int with base 10
**        x unsigned int with base 16 (using "abcdef")
**        X unsigned int with base 16 (using "ABCDEF")
**        % just "%"
**
**      example
**        - %d -> "15"
**          - flag:                NULL
**          - minimum field width: NULL
**          - precision:           NULL
**          - length modifier:     NULL
**          - conversions:         d
**        - %zd -> "15"
**          - flag:                NULL
**          - minimum field width: NULL
**          - precision:           NULL
**          - length modifier:     z
**          - conversions:         d
**        - %4d -> "  15"
**          - flag:                NULL
**          - minimum field width: 4
**          - precision:           NULL
**          - length modifier:     NULL
**          - conversions:         d
**        - %.3d -> "015"
**          - flag:                NULL
**          - minimum field width: NULL
**          - precision:           3
**          - length modifier:     NULL
**          - conversions:         d
**        - %4.3d -> "0015"
**          - flag:                NULL
**          - minimum field width: 4
**          - precision:           3
**          - length modifier:     NULL
**          - conversions:         d
**        - %*d
**          - flag:                NULL
**          - minimum field width: *
**          - precision:           NULL
**          - length modifier:     NULL
**          - conversions:         d
**        - %.*d
**          - flag:                NULL
**          - minimum field width: NULL
**          - precision:           *
**          - length modifier:     NULL
**          - conversions:         d
**        - %*.*d
**          - flag:                NULL
**          - minimum field width: *
**          - precision:           *
**          - length modifier:     NULL
**          - conversions:         d
**        - %05d -> "00015"
**          - flag:                0
**          - minimum field width: 5
**          - precision:           NULL
**          - length modifier:     NULL
**          - conversions:         d
**        - %- d -> "15   "
**          - flag:                -
**          - minimum field width: 5
**          - precision:           NULL
**          - length modifier:     NULL
**          - conversions:         d
*/

int			ft_printf(const char *src, ...)
{
	va_list		args;
	t_flag		*flag;
	int			cnt;

	cnt = 0;
	if (!(flag = (t_flag *)malloc(sizeof(t_flag))))
		return (-1);
	va_start(args, src);
	while (*src)
	{
		if (*src == '%')
		{
			initialize_flag(flag);
			src++;
			cnt += parse_format(&src, &args, flag);
		}
		else
		{
			ft_putchar_fd(*src++, 1);
			cnt++;
		}
	}
	free(flag);
	va_end(args);
	return (cnt);
}

static void	initialize_flag(t_flag *flag)
{
	flag->conversion = 0;
	flag->left_align = 0;
	flag->zero_padding = 0;
	flag->min_width = 0;
	flag->precision = -1;
}

static void show_flag(t_flag *flag)
{
	printf("flag: {\n");
	printf("\tconversion: %c\n", flag->conversion);
	printf("\tleft_align: %d\n", flag->left_align);
	printf("\tzero_padding: %d\n", flag->zero_padding);
	printf("\tmin_width: %d\n", flag->min_width);
	printf("\tprecision: %d\n", flag->precision);
	printf("}\n");
}

/*
**  parse_format
**
**    src: after '%'
**
**    flag
**      -: left align
**      0: zero padding
*/

static int	parse_format(const char** src, va_list *args, t_flag *flag)
{
	while (*src && ft_strchr("-0", **src))
	{
		if (**src == '-')
			flag->left_align = 1;
		if (**src == '0')
			flag->zero_padding = 1;
		(*src)++;
	}
	if (ft_isdigit(**src) || **src == '*')
		parse_min_width(src, args, flag);
	if (**src == '.')
		parse_precision(src, args, flag);
	flag->zero_padding = (flag->left_align ? 0 : flag->zero_padding);
	flag->conversion  = **src;
	(*src)++;
	return print_value(args, flag);
}

static void parse_precision(const char** src, va_list *args, t_flag *flag)
{
	int	precision;

	(*src)++;
	if (**src == '*')
	{
		(*src)++;
		precision = va_arg(*args, int);
		flag->precision = (precision >= 0 ? precision : -1);
		return ;
	}
	while (**src == '0')
		(*src)++;
	if (ft_isdigit(**src))
	{
		precision = ft_atoi(*src);
		flag->precision = (precision >= 0 ? precision : -1);
		*src += count_digits(flag->precision, 10);
		return ;
	}
	flag->precision = 0;
}

static void parse_min_width(const char** src, va_list *args, t_flag *flag)
{
	int	width;

	if (**src == '*')
	{
		(*src)++;
		width = va_arg(*args, int);
		if (width < 0)
		{
			flag->left_align = 1;
			width *= -1;
		}
		flag->min_width = width;
		return ;
	}
	flag->min_width = ft_atoi(*src);
	*src += count_digits(flag->min_width, 10);
	return ;
}

static int print_value(va_list *args, t_flag *flag)
{
	if (flag->conversion == 'c')
		return print_c(args, flag);
	if (flag->conversion == 's')
		return print_s(args, flag);
	if (ft_strchr("di", flag->conversion))
		return print_di(args, flag);
	if (flag->conversion == 'u')
		return print_u(args, flag);
	if (ft_strchr("pxX", flag->conversion))
		return print_pxX(args, flag);
	if (flag->conversion == '%')
		return print_modulo(flag);
	return (0);
}


static int print_c(va_list *args, t_flag *flag)
{
	int	c;

	c = va_arg(*args, int);
	if (flag->left_align)
	{
		ft_putchar_fd((char)c, 1);
		put_str_repeat((flag->zero_padding ? "0" : " "), flag->min_width - 1);
	}
	else
	{
		put_str_repeat((flag->zero_padding ? "0" : " "), flag->min_width - 1);
		ft_putchar_fd((char)c, 1);
	}
	return (flag->min_width > 0 ? flag->min_width : 1);
}

static int print_s(va_list *args, t_flag *flag)
{
	char *str;
	int free_flg;
	size_t len;
	int cnt;

	free_flg = 0;
	str = va_arg(*args, char *);
	if (!str)
	{
		free_flg = 1;
		str = ft_strdup("(null)");
	}
	if (0<=flag->precision && flag->precision < (int)ft_strlen(str))
	{
		if (free_flg)
		{
			free(str);
			str = ft_substr("(null)", 0, flag->precision);
		}
		else
		{
			free_flg = 1;
			str = ft_substr(str, 0, flag->precision);
		}
	}
	cnt = print_string(str, flag);
	if (free_flg)
		free(str);
	return (cnt);
}

static int print_di(va_list *args, t_flag *flag)
{
	long num;
	char *str;
	char *temp1;
	char *temp2;
	int cnt;

	num = (long)va_arg(*args, int);
	if (num == INT_MIN)
		str = ft_strdup("2147483648");
	else
		str = ft_itoa(num > 0 ? num : -num);
	if (flag->precision == 0 && num == 0)
	{
		free(str);
		str = ft_strdup("");
	}
	else
	{
		if (flag->precision > (int)ft_strlen(str))
		{
			temp1 = char_repeat_join('0', flag->precision - (int)ft_strlen(str), str);
			free(str);
			str = temp1;
		}
		if (flag->zero_padding && flag->precision == -1 && flag->min_width > ft_strlen(str) + (num < 0 ? 1 : 0))
		{
			temp1 = char_repeat_join('0', flag->min_width - ft_strlen(str) - (num < 0 ? 1 : 0), str);
			free(str);
			str = temp1;
		}
		else if (flag->zero_padding)
			flag->zero_padding = 0;
		if (num < 0)
		{
			temp1 = ft_strjoin("-", str);
			free(str);
			str = temp1;
		}
	}
	cnt = print_string(str, flag);
	free(str);
	return (cnt);
}

static int print_u(va_list *args, t_flag *flag)
{
	unsigned int num;
	char *str;
	char*temp1;
	int cnt;

	num = va_arg(*args, unsigned int);
	str = ft_uitoa(num);
	if (flag->precision == 0 && num == 0)
	{
		free(str);
		str = ft_strdup("");
	}
	else
	{
		if (flag->precision > (int) ft_strlen(str))
		{
			temp1 = char_repeat_join('0', flag->precision - (int)ft_strlen(str), str);
			free(str);
			str = temp1;
		}
		if (flag->zero_padding && flag->precision != -1 && flag->min_width > ft_strlen(str))
			flag->zero_padding = 0;
	}
	cnt = print_string(str, flag);
	free(str);
	return (cnt);
}

static int print_pxX(va_list *args, t_flag *flag)
{
	size_t num;
	char *str;
	char *temp;
	int cnt;

	num = (flag->conversion == 'p' ? (size_t)va_arg(*args, void *) : va_arg(*args, unsigned int));
	str = ft_utohex(num, flag->conversion == 'X' ? 1 : 0);
	if (flag->precision == 0 && num == 0)
	{
		free(str);
		str = ft_strdup("");
	}
	else
	{
		if (flag->conversion == 'p')
		{
			temp = ft_strjoin("0x", str);
			free(str);
			str = temp;
		}
		else
		{
			if (flag->precision > (int) ft_strlen(str))
			{
				temp = char_repeat_join('0', flag->precision - (int)ft_strlen(str), str);
				free(str);
				str = temp;
			}
			if (flag->zero_padding && flag->precision != -1 && flag->min_width > ft_strlen(str))
				flag->zero_padding = 0;
		}
	}

	cnt = print_string(str, flag);
	free(str);
	return (cnt);
}

static int print_modulo(t_flag *flag)
{
	if (flag->left_align)
	{
		ft_putchar_fd('%', 1);
		put_str_repeat((flag->zero_padding ? "0" : " "), flag->min_width - 1);
	}
	else
	{
		put_str_repeat((flag->zero_padding ? "0" : " "), flag->min_width - 1);
		ft_putchar_fd('%', 1);
	}
	return (flag->min_width > 0 ? flag->min_width : 1);
}

static int print_string(char *str, t_flag *flag)
{
	size_t len;

	len = ft_strlen(str);
	if (flag->left_align)
	{
		ft_putstr_fd(str, 1);
		put_str_repeat((flag->zero_padding ? "0" : " "), flag->min_width - len);
	}
	else
	{
		put_str_repeat((flag->zero_padding ? "0" : " "), flag->min_width - len);
		ft_putstr_fd(str, 1);
	}
	return (flag->min_width > len ? flag->min_width : len);

}

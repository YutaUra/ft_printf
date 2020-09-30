/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yura <yura@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 20:17:06 by yura              #+#    #+#             */
/*   Updated: 2020/09/30 21:48:18 by yura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(va_list *args, t_flag *flag)
{
	int	c;

	c = va_arg(*args, int);
	if (flag->left_align)
	{
		ft_putchar_fd((char)c, 1);
		put_str_repeat((flag->zero_padding ? '0' : ' '), flag->min_width - 1);
	}
	else
	{
		put_str_repeat((flag->zero_padding ? '0' : ' '), flag->min_width - 1);
		ft_putchar_fd((char)c, 1);
	}
	return (flag->min_width > 0 ? flag->min_width : 1);
}

int	print_s(va_list *args, t_flag *flag)
{
	char	*str;
	int		free_flg;
	size_t	len;
	int		cnt;

	free_flg = 0;
	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	if (0 <= flag->precision && flag->precision < (int)ft_strlen(str))
	{
		free_flg = 1;
		str = ft_substr(str, 0, flag->precision);
	}
	cnt = print_string(str, flag);
	if (free_flg)
		free(str);
	return (cnt);
}

int	print_di(va_list *args, t_flag *flag)
{
	long	num;
	char	*str;
	int		cnt;

	num = (long)va_arg(*args, int);
	if (num == INT_MIN)
		str = ft_strdup("2147483648");
	else
		str = ft_itoa(num > 0 ? num : -num);
	return (print_number(str, flag, num < 0 ? 1 : 0));
}

int	print_u(va_list *args, t_flag *flag)
{
	unsigned int	num;
	char			*str;
	int				cnt;

	num = va_arg(*args, unsigned int);
	str = ft_uitoa(num);
	return (print_number(str, flag, 0));
}

int	print_px(va_list *args, t_flag *flag)
{
	size_t	num;
	char	*str;
	char	*temp;
	int		cnt;

	num = (flag->conversion == 'p'
			? (size_t)va_arg(*args, void *)
			: va_arg(*args, unsigned int));
	str = ft_utohex(num, flag->conversion == 'X' ? 1 : 0);
	if (flag->conversion != 'p')
		return (print_number(str, flag, 0));
	temp = ft_strjoin("0x", str);
	free(str);
	cnt = print_string(temp, flag);
	free(temp);
	return (cnt);
}

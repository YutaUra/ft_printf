/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yura <yura@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 20:17:06 by yura              #+#    #+#             */
/*   Updated: 2020/09/30 21:48:35 by yura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_value(va_list *args, t_flag *flag)
{
	if (flag->conversion == 'c')
		return (print_c(args, flag));
	if (flag->conversion == 's')
		return (print_s(args, flag));
	if (ft_strchr("di", flag->conversion))
		return (print_di(args, flag));
	if (flag->conversion == 'u')
		return (print_u(args, flag));
	if (flag->conversion == 'p')
		return (print_p(args, flag));
	if (ft_strchr("xX", flag->conversion))
		return (print_x(args, flag));
	if (flag->conversion == '%')
		return (print_modulo(flag));
	return (0);
}

int	print_modulo(t_flag *flag)
{
	if (flag->left_align)
	{
		ft_putchar_fd('%', 1);
		put_str_repeat((flag->zero_padding ? '0' : ' '), flag->min_width - 1);
	}
	else
	{
		put_str_repeat((flag->zero_padding ? '0' : ' '), flag->min_width - 1);
		ft_putchar_fd('%', 1);
	}
	return (flag->min_width > 0 ? flag->min_width : 1);
}

int	print_p(va_list *args, t_flag *flag)
{
	size_t	num;
	ssize_t len;
	char	*str;
	char	*temp;
	int		cnt;

	num = (size_t)va_arg(*args, void *);
	temp = (num == 0 && flag->precision == 0)
			? ft_strdup("") : ft_utohex(num, 0);
	len = ft_strlen(temp);
	if (flag->precision > len)
	{
		str = char_repeat_join('0', flag->precision - len, temp);
		free(temp);
		temp = str;
	}
	str = ft_strjoin("0x", temp);
	free(temp);
	cnt = print_string(str, flag);
	free(str);
	return (cnt);
}

int	print_string(char *str, t_flag *flag)
{
	size_t len;

	len = ft_strlen(str);
	if (flag->left_align)
	{
		ft_putstr_fd(str, 1);
		put_str_repeat((flag->zero_padding ? '0' : ' '), flag->min_width - len);
	}
	else
	{
		put_str_repeat((flag->zero_padding ? '0' : ' '), flag->min_width - len);
		ft_putstr_fd(str, 1);
	}
	return (flag->min_width > (int)len ? flag->min_width : len);
}

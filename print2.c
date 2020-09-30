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
	if (ft_strchr("pxX", flag->conversion))
		return (print_px(args, flag));
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
	return (flag->min_width > len ? flag->min_width : len);
}

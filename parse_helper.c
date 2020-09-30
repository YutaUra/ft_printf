/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yura <yura@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 20:22:20 by yura              #+#    #+#             */
/*   Updated: 2020/09/30 20:39:15 by yura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_format(const char **src, va_list *args, t_flag *flag)
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
	flag->conversion = **src;
	(*src)++;
}

void	parse_precision(const char **src, va_list *args, t_flag *flag)
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

void	parse_min_width(const char **src, va_list *args, t_flag *flag)
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

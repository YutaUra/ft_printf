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
	if (flag->conversion != '\0')
		(*src)++;
}

static int printf_atoi(const char **src)
{
	int num;
	int minus;

	num = 0;
	while (**src == ' ')
		(*src)++;
	minus = (**src == '-') ? -1 : 1;
	if (minus == -1)
		(*src)++;
	while (ft_isdigit(**src))
	{
		num = num * 10 + (**src - '0');
		(*src)++;
	}
	return (num * minus);
}

void	parse_precision(const char **src, va_list *args, t_flag *flag)
{
	int	precision;

	(*src)++;
	if (**src == '*')
	{
		precision = va_arg(*args, int);
		(*src)++;
		flag->precision = (precision >= 0 ? precision : -1);
		return ;
	}
	precision = printf_atoi(src);
	if (precision < 0)
		precision = -1;
	flag->precision = precision;
}

void	parse_min_width(const char **src, va_list *args, t_flag *flag)
{
	int	width;

	if (**src == '*')
	{
		width = va_arg(*args, int);
		(*src)++;
		if (width < 0)
		{
			flag->left_align = 1;
			width *= -1;
		}
		flag->min_width = width;
		return ;
	}
	width = printf_atoi(src);
	if (width < 0)
	{
		flag->left_align = 1;
		width = width * -1;
	}
	flag->min_width = width;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yura <yura@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 20:45:48 by yura              #+#    #+#             */
/*   Updated: 2020/09/30 21:41:06 by yura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *free_swap(char *src, char *fr, char **dest)
{
	free(fr);
	if (src == NULL)
		return (NULL);
	*dest = src;
	return (*dest);
}

static int	print_number2(char *str, t_flag *flag, int minus)
{
	int		cnt;

	if (flag->zero_padding && flag->precision == -1
		&& flag->min_width > (int)ft_strlen(str) + minus)
	{
		if (free_swap(
				char_repeat_join('0',
					flag->min_width - (int)ft_strlen(str) - minus, str),
				str, &str) == NULL)
			return (-1);
	}
	else if (flag->zero_padding)
		flag->zero_padding = 0;
	if (minus)
	{
		if (free_swap(ft_strjoin("-", str), str, &str) == NULL)
			return (-1);
	}
	cnt = print_string(str, flag);
	free(str);
	return (cnt);
}

int			print_number(char *str, t_flag *flag, int minus)
{
	if (flag->precision == 0 && str[0] == '0')
	{
		free(str);
		return (print_string("", flag));
	}
	if (flag->precision > (int)ft_strlen(str))
	{
		if (free_swap(
				char_repeat_join('0',
					flag->precision - (int)ft_strlen(str), str),
				str, &str) == NULL)
			return (-1);
	}
	if (flag->zero_padding && flag->precision != -1
		&& flag->min_width > (int)ft_strlen(str))
		flag->zero_padding = 0;
	return (print_number2(str, flag, minus));
}

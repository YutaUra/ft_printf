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

static int	print_number2(char *str, t_flag *flag, int minus)
{
	char	*temp;
	int		cnt;

	if (flag->zero_padding && flag->precision == -1
		&& flag->min_width > (int)ft_strlen(str) + minus)
	{
		temp = char_repeat_join('0',
			flag->min_width - (int)ft_strlen(str) - minus, str);
		free(str);
		if (temp == NULL)
			return (-1);
		str = temp;
	}
	else if (flag->zero_padding)
		flag->zero_padding = 0;
	if (minus)
	{
		temp = ft_strjoin("-", str);
		free(str);
		if (temp == NULL)
			return (-1);
		str = temp;
	}
	cnt = print_string(str, flag);
	free(str);
	return (cnt);
}

int			print_number(char *str, t_flag *flag, int minus)
{
	char	*temp;

	if (flag->precision == 0 && str[0] == '0')
	{
		free(str);
		return (print_string("", flag));
	}
	if (flag->precision > (int)ft_strlen(str))
	{
		temp = char_repeat_join('0',
			flag->precision - (int)ft_strlen(str), str);
		free(str);
		if (temp == NULL)
			return (-1);
		str = temp;
	}
	if (flag->zero_padding && flag->precision != -1
		&& flag->min_width > (int)ft_strlen(str))
		flag->zero_padding = 0;
	return (print_number2(str, flag, minus));
}

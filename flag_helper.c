/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yura <yura@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 20:26:05 by yura              #+#    #+#             */
/*   Updated: 2020/09/30 20:28:11 by yura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_flag(t_flag *flag)
{
	flag->conversion = 0;
	flag->left_align = 0;
	flag->zero_padding = 0;
	flag->min_width = 0;
	flag->precision = -1;
}

void	show_flag(t_flag *flag)
{
	printf("flag: {\n");
	printf("\tconversion: %c\n", flag->conversion);
	printf("\tleft_align: %d\n", flag->left_align);
	printf("\tzero_padding: %d\n", flag->zero_padding);
	printf("\tmin_width: %d\n", flag->min_width);
	printf("\tprecision: %d\n", flag->precision);
	printf("}\n");
}

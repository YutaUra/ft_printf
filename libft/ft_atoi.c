/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yura <yura@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 00:48:22 by yura              #+#    #+#             */
/*   Updated: 2020/07/13 10:01:19 by yura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  ft_atoi
**    - args
**      - (const char *) nptr
**        数字表現を含む文字列
**
**    - return
**      nptrの数字表現を抜き出した物
**
**    - example
**      - ft_atoi("     ") -> 0
**      - ft_atoi("123") -> 123
**      - ft_atoi("  +12") -> 12
**      - ft_atoi("  -5") -> -5
*/

int	ft_atoi(const char *nptr)
{
	long	num;
	int		minus;

	num = 0;
	minus = 0;
	if (!nptr)
		return (0);
	while ((9 <= *nptr && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr++ == '-')
			minus = 1;
	}
	while (ft_isdigit(*nptr))
	{
		if (num > (LONG_MAX - *nptr + '0') / 10)
			return ((int)((minus == 1) ? LONG_MIN : LONG_MAX));
		num = 10 * num + (*nptr - '0');
		nptr++;
	}
	if (minus == 1)
		return ((int)-num);
	return ((int)num);
}

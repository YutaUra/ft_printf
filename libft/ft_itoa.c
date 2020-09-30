/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yura <yura@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 09:21:36 by yura              #+#    #+#             */
/*   Updated: 2020/07/13 12:44:34 by yura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_digit(int nbr)
{
	int size;

	size = 0;
	if (nbr < 0)
	{
		size++;
		nbr = -nbr;
	}
	while (nbr >= 10)
	{
		size++;
		nbr = nbr / 10;
	}
	return (size + 1);
}

void	set_nbr(char *dst, int n, int digit)
{
	if (n > 0)
	{
		while (n >= 10)
		{
			dst[digit--] = n % 10 + '0';
			n = n / 10;
		}
		dst[digit] = n + '0';
	}
	else
	{
		while (n <= -10)
		{
			dst[digit--] = -(n % 10) + '0';
			n = n / 10;
		}
		dst[digit--] = -n + '0';
		dst[digit] = '-';
	}
}

/*
**  ft_itoa
**    - args
**      - (int) n
**        文字列に変換する数字
**
**    - return
**      nを表すfree可能な文字列またはNULL
**
**    - example
**      - ft_itoa(10) -> "10"
**      - ft_itoa(1234) -> "1234"
**      - ft_itoa(-99) -> "-90"
*/

char	*ft_itoa(int n)
{
	char	*buf;
	int		i;
	int		digit;

	i = 0;
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	digit = count_digit(n);
	buf = (char *)malloc(sizeof(char) * (digit + 1));
	if (!buf)
		return (NULL);
	buf[digit--] = '\0';
	set_nbr(buf, n, digit);
	return (buf);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yura <yura@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 23:09:53 by yura              #+#    #+#             */
/*   Updated: 2020/09/30 21:50:57 by yura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	count_digits(long long nb, unsigned int base)
{
	size_t		cnt;
	size_t		n;

	cnt = 1;
	if (nb < 0)
	{
		n = nb * -1;
		cnt++;
	}
	else
		n = nb;
	while (n >= base)
	{
		n /= base;
		cnt++;
	}
	return (cnt);
}

void			put_str_repeat(char c, int cnt)
{
	while (cnt-- > 0)
		ft_putchar_fd(c, 1);
}

char			*char_repeat_join(char c, int repeat, char *str)
{
	char	*buf;
	int		i;

	if (!(buf = (char*)malloc(sizeof(char) * (repeat + ft_strlen(str) + 1))))
		return (NULL);
	i = 0;
	ft_memset(buf, c, repeat);
	ft_strlcpy(buf + repeat, str, ft_strlen(str) + 1);
	return (buf);
}

char			*ft_uitoa(unsigned int n)
{
	char			*buf;
	unsigned int	len;

	len = count_digits(n, 10);
	if (!(buf = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	buf[len--] = '\0';
	while (n > 9)
	{
		buf[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
	buf[len] = n + '0';
	return (buf);
}

char			*ft_utohex(size_t nb, int upper)
{
	size_t		digits;
	char		*buf;
	char		*hex;
	char		*upper_hex;

	hex = "0123456789abcdef";
	upper_hex = "0123456789ABCDEF";
	digits = count_digits(nb, 16);
	if ((buf = (char *)malloc(sizeof(char) * (digits + 1))) == NULL)
		return (NULL);
	buf[digits--] = '\0';
	if (nb == 0)
		buf[0] = '0';
	while (nb > 0)
	{
		buf[digits] = (upper ? upper_hex[nb % 16] : hex[nb % 16]);
		nb /= 16;
		digits--;
	}
	return (buf);
}

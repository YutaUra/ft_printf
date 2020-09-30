/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yura <yura@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 23:09:53 by yura              #+#    #+#             */
/*   Updated: 2020/09/30 08:03:42 by yura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	count_digits(long long nb, unsigned int base);
void put_str_repeat(char *str, int cnt);
char *char_repeat(char c, int repeat);
char *char_repeat_join(char c, int repeat, char *str);
char *ft_uitoa(unsigned int n);
char			*ft_utohex(size_t nb, int upper);

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

static size_t	count_udigits(size_t n, size_t base)
{
	size_t		cnt;

	cnt = 1;
	while (n >= base)
	{
		n /= base;
		cnt++;
	}
	return (cnt);
}

void put_str_repeat(char *str, int cnt)
{
	while (cnt-- > 0)
		ft_putstr_fd(str, 1);
}

char *char_repeat(char c, int repeat)
{
	char *buf;
	int i;

	if (!(buf = (char*)malloc((sizeof (char)) * (repeat + 1))))
		return (NULL);
	i = 0;
	while (i < repeat)
		buf[i++] = c;
	buf[i] = '\0';
	return (buf);
}

char *char_repeat_join(char c, int repeat, char *str)
{
	char *buf;
	int i;

	if (!(buf = (char*)malloc(sizeof(char) * (repeat + ft_strlen(str) + 1))))
		return (NULL);
	i = 0;
	while (i < repeat)
		buf[i++] = c;
	while (str[i - repeat] != '\0')
	{
		buf[i] = str[i - repeat];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

char *ft_uitoa(unsigned int n)
{
	char *buf;
	unsigned int len;

	len = count_digits(n, 10);
	if (!(buf = (char*)malloc(sizeof(char) *(len + 1))))
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
	digits = count_udigits(nb, 16);
	if (!(buf = (char *)malloc(sizeof(char) * (digits + 1))))
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

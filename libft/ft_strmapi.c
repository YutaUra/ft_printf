/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yura <yura@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 10:30:07 by yura              #+#    #+#             */
/*   Updated: 2020/07/13 12:41:23 by yura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  ft_strmapi
**    - args
**      - (const char *) s
**        map処理をする文字列
**
**      - (char) *f(unsigned int, char)
**        処理関数
**
**    - return
**      map処理で作られたfree可能な文字列またはNULL
*/

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*buf;

	if (!s || !f)
		return (NULL);
	i = 0;
	if (!(buf = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		buf[i] = f(i, s[i]);
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yura <yura@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 00:02:28 by yura              #+#    #+#             */
/*   Updated: 2020/07/13 12:41:33 by yura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  ft_strrchr
**    - args
**      - (const char *) s
**        検索文字列
**
**      - (int) c
**        検索文字
**
**    - return
**      検索文字がある場所のポインターまたはNULL
**
**    - description
**      sの一番後ろにあるcを返す
*/

char	*ft_strrchr(const char *s, int c)
{
	char *s2;

	s2 = (char *)s;
	while (*s2 != '\0')
		s2++;
	while (*s2 != c)
	{
		if (s2 == s)
			return (NULL);
		s2--;
	}
	return (s2);
}

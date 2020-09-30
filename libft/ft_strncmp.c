/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yura <yura@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 00:43:28 by yura              #+#    #+#             */
/*   Updated: 2020/07/13 09:45:04 by yura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  ft_strncmp
**    - args
**      - (const char *) s1
**        比較する文字列１
**
**      - (const char *) s2
**        比較する文字列２
**
**      - (size_t) n
**        比較する最大文字列
**
**    - return
**      s1とs2で文字が異なる箇所の差
**      文字列が一致する場合は0を返せば良い
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		if (i < n - 1)
			i++;
		else
			break ;
	}
	return ((int)((unsigned char)(s1[i]) - (unsigned char)(s2[i])));
}

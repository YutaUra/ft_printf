/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yura <yura@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 07:13:38 by yura              #+#    #+#             */
/*   Updated: 2020/07/13 12:06:26 by yura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strset(const char *s, const char *set)
{
	size_t i;

	i = 0;
	while (ft_strchr(set, s[i]) && s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strrset(const char *s, const char *set)
{
	size_t i;

	i = ft_strlen(s) - 1;
	while (ft_strchr(set, s[i]) && i >= 0)
		i--;
	return (i);
}

/*
**  ft_strtrim
**    - args
**      - (const char *) s
**        トリミングする文字列
**      - (const char *) set
**        除去する文字集合
**
**    - return
**      トリミングしたfree可能な文字列またはNULL
*/

char	*ft_strtrim(const char *s, const char *set)
{
	size_t start;
	size_t end;

	if (!s)
		return (NULL);
	start = ft_strset(s, set);
	end = ft_strrset(s, set) + 1;
	return (ft_substr(s, start, end - start));
}

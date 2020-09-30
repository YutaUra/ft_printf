/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yura <yura@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 00:06:55 by yura              #+#    #+#             */
/*   Updated: 2020/07/13 09:38:26 by yura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  ft_strnstr
**    - args
**      - (const char *) haystack
**        検索対象の文字列
**
**      - (const char *) needle
**        検索する部分列
**
**      - (size_t) len
**        切り取る文字数
**
**    - return
**      検索文字がある場所の最初の文字のポインターまたはNULL
**
**    - description
**      検索開始から対象文字が見つかるところまでを含めてlen以下になっている必要がある。
**
**    - example
**      - ft_strstr("abcdef", "abc", 6) -> "abcdef"
**      - ft_strstr("abcdef", "abc", 3) -> "abcdef"
**      - ft_strstr("abcdef", "abc", 2) -> (NULL)
**      - ft_strstr("abcdef", "cd", 4) -> "cdef"
**      - ft_strstr("abcdef", "cd", 3) -> (NULL)
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t offset;
	size_t needle_len;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	if (!len)
		return (NULL);
	needle_len = ft_strlen(needle);
	while (haystack[i] != '\0' && i < len - needle_len + 1)
	{
		offset = 0;
		while (haystack[i + offset] == needle[offset] && needle[offset] != '\0')
			offset++;
		if (needle[offset] == '\0')
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}

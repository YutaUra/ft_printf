/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yura <yura@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 06:48:46 by yura              #+#    #+#             */
/*   Updated: 2020/07/13 10:20:25 by yura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  ft_substr
**    - args
**      - (const char *) s
**        切り取る対象
**
**      - (unsigned int) start
**        切り取りの開始位置
**
**      - (size_t) len
**        切り取る文字数
**
**    - return
**      free可能な切り取った文字列
**
**    - behavior
**      - sの長さがstartより短い場合
**        空の文字列を返す
**
**      - lenがstartからsの最後よりも長い場合
**        sの最後までとみなす
*/

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	s_len;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < start)
		return (ft_strdup(""));
	if (s_len - start < len)
		len = s_len - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

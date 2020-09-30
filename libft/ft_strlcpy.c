/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yura <yura@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 23:37:06 by yura              #+#    #+#             */
/*   Updated: 2020/07/13 09:06:27 by yura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  ft_strlcpy
**    - args
**      - (char *) dst
**        あて先文字列
**
**      - (const char *)src
**        ソース文字列
**
**      - (size_t) size
**        あて先文字列のサイズ
**
**    - return
**      作成しようとした文字列の長さ(srcの長さ)
**
**    - description
**      dstはsize分だけ領域を持っているとして処理をする。
**
**    - behavior
**      - srcの長さがsizeより小さい場合
**        src全てを移動させる
**
**      - そうではない場合
**        srcのうちsize - 1分だけ移動させる。
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t len;

	if (!dst || !size)
		return (!src ? 0 : ft_strlen(src));
	i = ft_strlen(src);
	len = i < size ? i : size - 1;
	ft_memcpy(dst, src, len);
	dst[len] = '\0';
	return (i);
}

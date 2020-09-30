/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yura <yura@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 23:47:56 by yura              #+#    #+#             */
/*   Updated: 2020/07/13 09:06:58 by yura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  ft_strlcat
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
**      作成しようとした文字列の長さ。
**      sizeを上限としている
**
**    - description
**      dstはsize分だけ領域を持っているとして処理をする。
**
**    - behavior
**      - dstの長さがsizeより大きい場合
**        sizeの長さ以上は処理できないので、srcの長さとsizeを返す
**        ゆうなればエラー判定となっている。利用側は返り値がsize以上の場合失敗したとみなす
**
**      - そうではない場合
**        dstの末尾にsrcをくっつける。
**        くっつけるサイズはsizeからsrcを引いた値。
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t dst_size;

	i = 0;
	dst_size = ft_strlen(dst);
	if (dst_size >= size)
		return (ft_strlen(src) + size);
	return (dst_size + ft_strlcpy(dst + dst_size, src, size - dst_size));
}

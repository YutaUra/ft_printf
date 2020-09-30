/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yura <yura@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 06:32:29 by yura              #+#    #+#             */
/*   Updated: 2020/07/14 16:43:33 by yura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  ft_calloc
**    - args
**      - (size_t) count
**        オブジェクトの数
**
**      - (size_t) size
**        オブジェクトのサイズ
**
**    - return
**      count * sizeを0埋めしたfree可能な領域またはNULL
*/

void	*ft_calloc(size_t count, size_t size)
{
	char *buf;

	if (!(buf = (char *)malloc(size * count)))
		return (NULL);
	return (ft_memset(buf, 0, count * size));
}

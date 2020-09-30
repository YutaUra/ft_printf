/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yura <yura@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 07:08:46 by yura              #+#    #+#             */
/*   Updated: 2020/07/15 20:29:24 by yura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  ft_strjoin
**    - args
**      - (const char *) s1
**        文字列１
**      - (const char *) s2
**        文字列２
**
**    - return
**      s1とs2を結合したfree可能な文字列またはNULL
*/

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*buf;
	size_t	s1_size;
	size_t	s2_size;
	size_t	buf_size;

	if (!s1)
	{
		if (!s2)
			return (ft_strdup(""));
		return (ft_strdup(s2));
	}
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	buf_size = s1_size + s2_size + 1;
	if (!(buf = (char *)malloc(sizeof(char) * buf_size)))
		return (NULL);
	ft_strlcpy(buf, s1, buf_size);
	ft_strlcpy(buf + s1_size, s2, buf_size);
	return (buf);
}

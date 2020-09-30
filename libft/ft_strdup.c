/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yura <yura@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 06:39:12 by yura              #+#    #+#             */
/*   Updated: 2020/07/13 12:42:25 by yura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*buf;
	size_t	size;

	size = ft_strlen(s) + 1;
	buf = (char *)malloc(sizeof(const char) * size);
	if (!buf)
		return (NULL);
	ft_strlcpy(buf, s, size);
	return (buf);
}

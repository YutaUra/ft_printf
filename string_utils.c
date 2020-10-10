/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yura <yura@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 11:04:08 by yura              #+#    #+#             */
/*   Updated: 2020/10/10 11:05:56 by yura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*free_swap(char *src, char *fr, char **dest)
{
	free(fr);
	if (src == NULL)
		return (NULL);
	*dest = src;
	return (*dest);
}

char	*char_repeat_join(char c, int repeat, char *str)
{
	char	*buf;
	int		i;

	if (!(buf = (char*)malloc(sizeof(char) * (repeat + ft_strlen(str) + 1))))
		return (NULL);
	i = 0;
	ft_memset(buf, c, repeat);
	ft_strlcpy(buf + repeat, str, ft_strlen(str) + 1);
	return (buf);
}

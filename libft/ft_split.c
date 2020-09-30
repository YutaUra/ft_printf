/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yura <yura@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 08:33:05 by yura              #+#    #+#             */
/*   Updated: 2020/07/14 15:50:38 by yura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** TODO: delimiterが'\0'のとき
*/

int		spliter(char **buf, const char *str, char delimiter, size_t buf_size)
{
	size_t start;
	size_t end;

	if (buf_size == 1)
	{
		*buf = NULL;
		return (0);
	}
	start = 0;
	while (str[start] == delimiter && str[start] != '\0')
		start++;
	end = start + 1;
	while (str[end] != delimiter && str[end] != '\0')
		end++;
	if (!(*buf = ft_substr(str, start, end - start)))
		return (-1);
	return (spliter(buf + 1, str + end, delimiter, buf_size - 1));
}

/*
**  ft_split_size
**    - args
**      - (const char *)s
**        文字列
**      - (char) c
**        分割文字
**
**    - return
**      sをcで分割した場合の分割要素数
**
**    - example
**      - ft_split_size("", '\0') -> 0
**      - ft_split_size("aaa", '\0') -> 1
**      - ft_split_size("", 'a') -> 0
**      - ft_split_size("aaa", 'a') -> 0
**      - ft_split_size("aaabbb", 'a') -> 1
**      - ft_split_size("bbbaaa", 'a') -> 1
**      - ft_split_size("bbbaaabbb", 'a') -> 2
*/

size_t	ft_split_size(const char *s, char c)
{
	size_t len;

	if (*s == '\0')
		return (0);
	if (c == '\0')
		return (1);
	while (*s == c)
		s++;
	if (*s == '\0')
		return (0);
	len = 1;
	while (*s++ != '\0')
	{
		if (*s == c)
		{
			len++;
			while (*s == c)
				s++;
			if (*s == '\0')
				len--;
		}
	}
	return (len);
}

void	clear_split(char **buf)
{
	int i;

	i = 0;
	while (buf[i])
	{
		free(buf[i]);
		i++;
	}
	free(buf);
}

/*
**  ft_split
**    - args
**      - (const char *) s
**        分割する文字列
**      - (char) delimiter
**        分割文字
**
**    - return
**       delimiterで分割したfree可能な文字列の配列またはNULL
*/

char	**ft_split(const char *s, char delimiter)
{
	char	**buf;
	size_t	buf_size;

	if (!s)
	{
		if (!(buf = (char **)malloc(sizeof(char *) * 1)))
			return (NULL);
		buf[0] = NULL;
		return (buf);
	}
	buf_size = ft_split_size(s, delimiter) + 1;
	if (!(buf = (char **)ft_calloc(buf_size, sizeof(char *))))
		return (NULL);
	if ((spliter(buf, s, delimiter, buf_size)) == -1)
	{
		clear_split(buf);
		return (NULL);
	}
	return (buf);
}

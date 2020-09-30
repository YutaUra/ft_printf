/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yura <yura@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 11:02:00 by yura              #+#    #+#             */
/*   Updated: 2020/07/13 07:53:15 by yura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *buf;

	buf = (t_list *)malloc(sizeof(t_list));
	if (!buf)
		return (NULL);
	buf->content = content;
	buf->next = NULL;
	return (buf);
}

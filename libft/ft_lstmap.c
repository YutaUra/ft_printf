/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yura <yura@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 11:42:10 by yura              #+#    #+#             */
/*   Updated: 2020/07/15 21:56:46 by yura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *buf;
	t_list *temp;

	if (!lst || !f)
		return (NULL);
	if (!(buf = ft_lstnew(f(lst->content))))
		return (NULL);
	temp = buf;
	while (lst->next)
	{
		if (!(temp->next = ft_lstnew(f(lst->next->content))))
		{
			ft_lstclear(&buf, del);
			return (NULL);
		}
		lst = lst->next;
		temp = temp->next;
	}
	temp->next = NULL;
	return (buf);
}

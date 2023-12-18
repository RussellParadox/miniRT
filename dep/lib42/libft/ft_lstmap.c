/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:57:05 by gdornic           #+#    #+#             */
/*   Updated: 2023/02/18 17:59:56 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_ele;
	t_list	*lst_cpy;

	(void)del;
	lst_cpy = lst;
	new_list = NULL;
	while (lst_cpy != NULL && f != (void *)0)
	{
		new_ele = ft_lstnew((*f)(lst_cpy->content));
		ft_lstadd_back(&new_list, new_ele);
		lst_cpy = lst_cpy->next;
	}
	return (new_list);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:27:59 by gdornic           #+#    #+#             */
/*   Updated: 2023/02/17 20:44:28 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_cpy;
	t_list	*tmp;

	if (lst != NULL)
	{
		lst_cpy = *lst;
		while (lst_cpy != NULL && del != (void *)0)
		{
			tmp = lst_cpy->next;
			ft_lstdelone(lst_cpy, del);
			lst_cpy = tmp;
		}
		*lst = NULL;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:49:06 by gdornic           #+#    #+#             */
/*   Updated: 2023/02/17 20:52:29 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*lst_cpy;

	lst_cpy = lst;
	while (lst_cpy != NULL && f != (void *)0)
	{
		(*f)(lst_cpy->content);
		lst_cpy = lst_cpy->next;
	}
}

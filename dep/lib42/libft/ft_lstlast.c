/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:45:05 by gdornic           #+#    #+#             */
/*   Updated: 2023/02/17 15:48:13 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*lst_cpy;

	lst_cpy = lst;
	while (lst_cpy != NULL && lst_cpy->next != NULL)
	{
		lst_cpy = lst_cpy->next;
	}
	return (lst_cpy);
}

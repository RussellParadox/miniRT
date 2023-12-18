/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:34:35 by gdornic           #+#    #+#             */
/*   Updated: 2023/02/16 21:52:06 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*lst_iter;

	lst_iter = lst;
	size = 0;
	while (lst_iter != NULL)
	{
		lst_iter = lst_iter->next;
		size++;
	}
	return (size);
}

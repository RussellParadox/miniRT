/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:35:28 by gdornic           #+#    #+#             */
/*   Updated: 2023/02/16 19:46:41 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_ele;

	new_ele = malloc(sizeof(t_list));
	if (new_ele == NULL)
		return (NULL);
	new_ele->content = content;
	new_ele->next = NULL;
	return (new_ele);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 23:14:43 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/04 00:02:11 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_list	*scene_create(int fd)
{
	t_list	*scene;
	t_list	*new;
	t_obj	*object;

	scene = NULL;
	object = next_object(fd);
	while (object != NULL)
	{
		new = ft_lstnew(object);
		if (new == NULL)
			break ;
		ft_lstadd_back(&scene, new);
		object = next_object(fd);
	}
	if (errno == ENOMEM)
		ft_lstclear(&scene, &object_free);
	return (scene);
}
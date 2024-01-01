/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:05:43 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/01 15:30:19 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_obj	*next_object(int fd)
{
	t_obj	*object;
	char	*line;
	char	**object_data;

	line = get_next_line(fd);
	while (line != NULL && is_empty(line))
	{
		free(line);
		line = get_next_line(fd);
	}
	if (line == NULL)
		return (NULL);
	object_data = ft_split(line, ' ');
	free(line);
	if (object_data == NULL)
		return (NULL);
	object = object_create(object_data);
	array_free(object_data);
	return (object);
}
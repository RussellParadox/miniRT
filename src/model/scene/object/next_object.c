/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:05:43 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/03 23:51:16 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	is_empty(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (*line == '\n' || *line == '\0')
		return (1);
	return (0);
}

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
	array_free(object_data, 2);
	return (object);
}
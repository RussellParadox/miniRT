/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:05:43 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/10 11:44:41 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	is_empty(char *line)
{
	while (*line == ' ')
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
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	object_data = ft_split(line, ' ');
	free(line);
	if (object_data == NULL)
		return (NULL);
	object = object_create(object_data);
	array_free(object_data, 2);
	return (object);
}
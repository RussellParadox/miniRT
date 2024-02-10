/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_fail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:35:26 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/10 16:19:06 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	line_fail(char *line)
{
	char	**data;
	int		result;

	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	data = ft_split(line, ' ');
	if (data == NULL)
		return (1);
	result = 1;
	if (!str_cmp(data[0], "A") && ambient_lightning_rule(data))
		result = 0;
	else if (!str_cmp(data[0], "C") && camera_rule(data))
		result = 0;
	else if (!str_cmp(data[0], "L") && light_rule(data))
		result = 0;
	else if (!str_cmp(data[0], "sp") && sphere_rule(data))
		result = 0;
	else if (!str_cmp(data[0], "pl") && plane_rule(data))
		result = 0;
	else if (!str_cmp(data[0], "cy") && cylinder_rule(data))
		result = 0;
	else
		put_error("Unknown identifier");
	array_free(data, 2);
	return (result);
}

int	argument_fail(int argc, char *argv[])
{
	char	*line;
	int		fd;

	if (argc != 2)
		return (put_error("miniRT need one and only argument."));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (put_error("Can't open file"));
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!is_empty(line) && line_fail(line))
			return (1);
		free(line);
		line = get_next_line(fd);
	}
	if (errno == ENOMEM)
		return (put_error("Memory problem"));
	close(fd);
	return (0);
}
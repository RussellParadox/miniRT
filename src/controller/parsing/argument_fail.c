/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_fail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:35:26 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 10:43:20 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	identifier_fail(char *id)
{
	if (!str_cmp(id, "A"))
		return (0);
	else if (!str_cmp(id, "C"))
		return (0);
	else if (!str_cmp(id, "L"))
		return (0);
	else if (!str_cmp(id, "sp"))
		return (0);
	else if (!str_cmp(id, "pl"))
		return (0);
	else if (!str_cmp(id, "cy"))
		return (0);
	put_error("Unknown identifier");
	return (1);
}

int	line_fail(char *line)
{
	char	**data;
	int		result;

	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	data = ft_split(line, ' ');
	if (data == NULL)
		return (1);
	result = 0;
	if (!str_cmp(data[0], "A") && ambient_lightning_rule(data))
		result = 1;
	else if (!str_cmp(data[0], "C") && camera_rule(data))
		result = 1;
	else if (!str_cmp(data[0], "L") && light_rule(data))
		result = 1;
	else if (!str_cmp(data[0], "sp") && sphere_rule(data))
		result = 1;
	else if (!str_cmp(data[0], "pl") && plane_rule(data))
		result = 1;
	else if (!str_cmp(data[0], "cy") && cylinder_rule(data))
		result = 1;
	if (identifier_fail(data[0]))
		result = 1;
	array_free(data, 2);
	return (result);
}

int	argument_fail(int argc, char *argv[])
{
	char	*line;
	int		fd;
	int		result;

	if (argc != 2)
		return (put_error("miniRT need one and only argument."));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (put_error("Can't open file"));
	line = get_next_line(fd);
	result = 0;
	while (line != NULL)
	{
		if (!is_empty(line) && line_fail(line))
			result = 1;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (errno == ENOMEM)
		return (put_error("Memory problem"));
	return (result);
}

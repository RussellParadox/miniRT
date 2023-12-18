/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:29:06 by gdornic           #+#    #+#             */
/*   Updated: 2023/04/02 04:41:01 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_addnstack(char *line, char *stack, size_t n)
{
	char	*tmp;

	if (line == NULL)
	{
		line = (char *)malloc(sizeof(char));
		if (line == NULL)
			return (NULL);
		ft_memset_gnl(line, '\0', 1);
	}
	tmp = line;
	line = ft_strnjoin(tmp, stack, n);
	free(tmp);
	return (line);
}

static char	*get_the_line(int fd, char *stack)
{
	char	*line;
	char	*first_occ;
	ssize_t	read_size;

	if (stack[0] == '\0')
	{
		read_size = read(fd, stack, BUFFER_SIZE);
		if (read_size <= 0)
			return (NULL);
	}
	first_occ = ft_strchr_gnl(stack, '\n');
	line = NULL;
	while (first_occ == NULL && stack[0] != '\0')
	{
		line = ft_addnstack(line, stack, BUFFER_SIZE);
		ft_memset_gnl(stack, '\0', BUFFER_SIZE);
		read_size = read(fd, stack, BUFFER_SIZE);
		if (read_size < 0)
			return (NULL);
		first_occ = ft_strchr_gnl(stack, '\n');
	}
	line = ft_addnstack(line, stack, (first_occ - stack + 1));
	ft_stackmove(stack);
	return (line);
}

static void	ft_free_stack(char **stack)
{
	free(*stack);
	*stack = NULL;
}

static char	*slow_get_line(int fd)
{
	static char	*stack[4096];
	char		*line;
	size_t		stack_size;

	if (fd >= 0 && stack[fd] == NULL)
	{
		stack_size = BUFFER_SIZE + 1;
		if (stack_size * sizeof(char) / sizeof(char) != stack_size \
			|| stack_size * sizeof(char) / stack_size != sizeof(char))
			return (NULL);
		stack[fd] = (char *)malloc(stack_size * sizeof(char));
		if (stack[fd] == NULL)
			return (NULL);
		ft_memset_gnl(stack[fd], '\0', stack_size);
	}
	if (read(fd, 0, 0) < 0)
	{
		ft_free_stack(&stack[fd]);
		return (NULL);
	}
	line = get_the_line(fd, stack[fd]);
	if (stack[fd] != NULL && (stack[fd][0] == '\0' || line == NULL))
		ft_free_stack(&stack[fd]);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;

	line = NULL;
	line = slow_get_line(fd);
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 07:55:00 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/04 00:07:06 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int argc, char *argv[])
{
	t_list	*scene;
	int		fd;
	int		status;

	errno = 0;
	(void)argc;
 /*
	if (argument_check(argc, argv))
		return (EXIT_FAILURE);
*/
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (EXIT_FAILURE);
	scene = scene_create(fd);
	close(fd);
	if (errno == ENOMEM)
		return (EXIT_FAILURE);
	status = controller_loop(scene);
	ft_lstclear(&scene, &object_free);
	return (status);
}
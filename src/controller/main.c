/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 07:55:00 by gdornic           #+#    #+#             */
/*   Updated: 2023/12/30 22:51:25 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int argc, char *argv[])
{
	t_list	*scene;
	int		status;

	if (argument_check(argc, argv))
		return (EXIT_FAILURE);
	scene = scene_create(argv);
	if (scene == NULL)
		return (EXIT_FAILURE);
	status = controller_loop(scene);
	ft_lstclear(&scene, &object_free);
	return (status);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 22:55:53 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/14 20:40:43 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	controller_routine(void *param[2])
{
	t_mlx	*mlx;
	t_list	*scene;
	t_img	*canva;

	mlx = param[0];
	scene = param[1];
	canva = image_create(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (canva == NULL)
		return (-1);
	raytracing_render(canva, scene);
	view_routine(canva, mlx);
	image_free(canva, mlx);
	if (errno == ENOMEM)
		return (loop_end_hook(param));
	return (0);
}
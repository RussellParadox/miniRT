/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 22:55:53 by gdornic           #+#    #+#             */
/*   Updated: 2023/12/30 23:54:26 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	controller_routine(void *param[2])
{
	t_mlx	*mlx;
	t_list	*scene;
	t_img	canva;

	mlx = (t_mlx *)param[0];
	scene = (t_list *)param[1];
	image_init(&canva, mlx->instance, WINDOW_WIDTH, WINDOW_HEIGHT);
	raytracing_render(&canva, scene);
	view_routine(canva, mlx);
	mlx_destroy_image(mlx->instance, canva.instance);
	return (0);
}
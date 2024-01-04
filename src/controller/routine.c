/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 22:55:53 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/04 10:53:20 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	controller_routine(void *param[2])
{
	t_mlx	*mlx;
	t_list	*scene;
	t_img	*canva;
	static int	r = 0;

	mlx = param[0];
	scene = param[1];
	(void)scene;
	canva = image_create(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (canva == NULL)
		return (-1);
	//raytracing_render(canva, scene);
	if (r >= 300)
		r = 0;
	else
		r += 80;
	draw_circle(canva, 0, 0, r);
	view_routine(canva, mlx);
	image_free(canva, mlx);
	return (0);
}
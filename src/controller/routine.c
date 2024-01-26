/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 22:55:53 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/24 16:34:07 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	animation_light_horizontale(t_list *scene, float x)
{
	t_light	*light;

	light = (t_light *)object_find("L", scene);
	light->coordinate->x += x;
}

void	animation_parabole(t_vector *r, float a, float b, float c)
{
	r->y = a * powf(r->x, 2) + b * r->x + c;
	r->x += 0.1;
	if (r->y < 0)
		r->x = 0;
}

//r: center of object
//center: center of rotation
void	animation_circular_rotation(t_vector *r, t_vector *center, float radius, float angle)
{
	static float	prev_angle;

	r->x = center->x + radius * cos(prev_angle + angle);
	r->y = center->y;
	r->z = center->z + radius * sin(prev_angle + angle);
	prev_angle += angle;
	if (fabs(prev_angle) >= 2 * M_PI)
		prev_angle = 0;
}

int	controller_routine(void *param[2])
{
	t_mlx	*mlx;
	t_list	*scene;
	t_img	*canva;
	clock_t	start;

	mlx = param[0];
	scene = param[1];
	canva = image_create(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (canva == NULL)
		return (-1);
	start = clock();
	raytracing_render(canva, scene);
	printf("time: %f s\n", (float)(clock() - start) / CLOCKS_PER_SEC);
	fflush(stdout);
	view_routine(canva, mlx);
	image_free(canva, mlx);
	if (errno == ENOMEM)
		return (loop_end_hook(param));
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 22:55:53 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/20 04:17:05 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	animation_light_horizontale(t_list *scene, float x)
{
	t_light	*light;

	light = (t_light *)object_find("L", scene);
	light->coordinate->x += x;
}

void	animation_sphere_parabole(t_list *scene, float a, float b, float c)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)object_find("sp", scene);
	if (sphere == NULL)
		return ;
	sphere->coordinate->y = a * powf(sphere->coordinate->x, 2) + b * sphere->coordinate->x + c;
	sphere->coordinate->x += 1.8;
	if (sphere->coordinate->y < 0)
		sphere->coordinate->x = 0;
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

	mlx = param[0];
	scene = param[1];
	canva = image_create(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (canva == NULL)
		return (-1);
	animation_sphere_parabole(scene, -0.2, 6, 40);
	animation_light_horizontale(scene, -0.3);
	//animation_circular_rotation(((t_sphere *)object_find("sp", scene))->coordinate, &((t_vector) {0, 20, 25}), 20, M_PI / 60);
	animation_circular_rotation(((t_light *)object_find("L", scene))->coordinate, &((t_vector) {0, 50, 25}), 30, -M_PI / 100);
	raytracing_render(canva, scene);
	view_routine(canva, mlx);
	image_free(canva, mlx);
	if (errno == ENOMEM)
		return (loop_end_hook(param));
	return (0);
}
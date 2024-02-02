/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:59:07 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/02 15:06:53 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	light_effect(t_vector normal, t_list *scene, t_closest closest, t_ray ray)
{
	t_color		obj_color;
	t_color		color;
	t_vector	intensity;
	t_vector	p;

	p = ray_point(ray, closest.parameter);
	obj_color = object_color(closest.object, p, normal);
	normal = vector_sum(normal, bump_normal(closest.object, p, normal));
	intensity = light_intensity(normal, scene, p, vector_sub((t_vector){0, 0, 0}, ray.direction), object_specular(closest.object));
	color.red = obj_color.red * intensity.x;
	color.green = obj_color.green * intensity.y;
	color.blue = obj_color.blue * intensity.z;
	color.sum = color.red + color.green + color.blue;
	if (color.red > 255)
		color.red = 255;
	if (color.green > 255)
		color.green = 255;
	if (color.blue > 255)
		color.blue = 255;
	return (color);
}
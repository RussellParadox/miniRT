/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:59:07 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 10:32:04 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	color_protection(t_color *color)
{
	if (color->red > 255)
		color->red = 255;
	if (color->green > 255)
		color->green = 255;
	if (color->blue > 255)
		color->blue = 255;
}

t_color	light_effect(t_vector normal, t_list *scene, \
t_closest closest, t_ray ray)
{
	t_color		obj_color;
	t_color		color;
	t_vector	intensity;
	t_vector	p;
	float		s;

	p = ray_point(ray, closest.parameter);
	obj_color = object_color(closest.object, p, normal);
	normal = vector_normalized(vector_sum(normal, \
	bump_normal(closest.object, p, normal)));
	s = object_specular(closest.object);
	capsule(&s);
	intensity = light_intensity(normal, scene, p, \
	vector_sub((t_vector){0, 0, 0}, ray.direction));
	color.red = obj_color.red * intensity.x;
	color.green = obj_color.green * intensity.y;
	color.blue = obj_color.blue * intensity.z;
	color.sum = color.red + color.green + color.blue;
	color_protection(&color);
	return (color);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 22:37:32 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/20 08:14:02 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_color	reflective_color(t_color local, t_color reflective, float r)
{
	t_color	lr;

	lr.red = local.red * (1 - r) + reflective.red * r;
	lr.green = local.green * (1 - r) + reflective.green * r;
	lr.blue = local.blue * (1 - r) + reflective.blue * r;
	if (lr.red > 255)
		lr.red = 255;
	if (lr.green > 255)
		lr.green = 255;
	if (lr.blue > 255)
		lr.blue = 255;
	lr.sum = lr.red + lr.green + lr.blue;
	return (lr);
}

static t_closest	closest_intersection(t_ray *ray, t_list *scene)
{
	float		parameter;
	float		closest_parameter;
	t_obj		*object;
	t_obj		*closest_object;

	closest_object = NULL;
	closest_parameter = FLT_MAX;
	while (scene != NULL)
	{
		object = scene->content;
		parameter = ray_intersect(ray, object);
		if (parameter < closest_parameter && !(parameter < ray->parameter_min))
		{
			closest_parameter = parameter;
			closest_object = object;
		}
		scene = scene->next;
	}
	return ((t_closest){closest_object, closest_parameter});
}

//ray = ray->origin + parameter * ray->direction
static t_color	ray_trace(t_ray *ray, t_list *scene, int depth)
{
	t_closest	closest;
	t_vector	intersection;
	t_vector	normal;
	t_color		local_color;
	t_color		reflect_color;
	float		r;

	closest = closest_intersection(ray, scene);
	if (closest.object == NULL)
		return ((t_color){0, 0, 0, 0});
	intersection.x = ray->origin->x + closest.parameter * ray->direction->x;
	intersection.y = ray->origin->y + closest.parameter * ray->direction->y;
	intersection.z = ray->origin->z + closest.parameter * ray->direction->z;
	object_normal_init(&normal, closest.object, &intersection);
	local_color = light_effect(normal, scene, closest.object, &intersection);
	r = object_reflective(closest.object);
	if (depth <= 0 || !(r > 0))
		return (local_color);
	vector_init(ray->origin, intersection.x, intersection.y, intersection.z);
	vector_init(ray->direction, -ray->direction->x, -ray->direction->y, -ray->direction->z);
	reflection_init(ray->direction, &normal, ray->direction);
	ray->parameter_min = PRECISION;
	reflect_color = ray_trace(ray, scene, depth - 1);
	return (reflective_color(local_color, reflect_color, r));
}

static void	ray_set(t_ray *ray, t_camera *camera, t_vector *pixel, t_viewport *viewport)
{
	ray->origin->x = camera->coordinate->x;
	ray->origin->y = camera->coordinate->y;
	ray->origin->z = camera->coordinate->z;
	ray->direction->x = camera->orientation->x + pixel->x * viewport->width_ratio;
	ray->direction->y = camera->orientation->y + pixel->y * viewport->height_ratio;
	ray->direction->z = camera->orientation->z;
	ray->parameter_min = CAMERA_VIEWPORT_DISTANCE;
}

void	raytracing_method(t_img *canva, t_list *scene, t_viewport *viewport, t_ray *ray)
{
	t_camera	*camera;
	t_color		color;
	int			x;
	int			y;

	camera = (t_camera *)object_find("C", scene);
	color = (t_color){0, 0, 0, 0};
	if (camera != NULL)
	{
		x = -canva->width / 2;
		while (x <= canva->width / 2)
		{
			y = -canva->height / 2;
			while (y <= canva->height / 2)
			{
				ray_set(ray, camera, &((t_vector) {x, y, 0}), viewport);
				color = ray_trace(ray, scene, 3);
				canva_pixel_put(canva, x, y, trgb_create(0, color.red, color.green, color.blue));
				y++;
			}
			x++;
		}
	}
}
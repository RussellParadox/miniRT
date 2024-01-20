/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 22:37:32 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/20 01:21:44 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

//ray = ray->origin + parameter * ray->direction
static void	ray_trace(t_color *color, t_ray *ray, t_list *scene)
{
	t_list		*scene_cpy;
	float		parameter;
	float		parameter_min;
	t_obj		*object;
	t_obj		*closest_object;
	t_vector	intersection;

	scene_cpy = scene;
	closest_object = NULL;
	parameter_min = FLT_MAX;
	while (scene != NULL)
	{
		object = scene->content;
		parameter = ray_intersect(ray, object);
		if (parameter < parameter_min && parameter >= CAMERA_VIEWPORT_DISTANCE)
		{
			parameter_min = parameter;
			closest_object = object;
		}
		scene = scene->next;
	}
	intersection.x = ray->origin->x + parameter_min * ray->direction->x;
	intersection.y = ray->origin->y + parameter_min * ray->direction->y;
	intersection.z = ray->origin->z + parameter_min * ray->direction->z;
	light_effect(color, scene_cpy, closest_object, &intersection);
}

static void	ray_direction_set(t_ray *ray, t_camera *camera, t_vector *pixel, t_viewport *viewport)
{
	ray->direction->x = camera->orientation->x + pixel->x * viewport->width_ratio;
	ray->direction->y = camera->orientation->y + pixel->y * viewport->height_ratio;
	ray->direction->z = camera->orientation->z;
}

void	raytracing_method(t_img *canva, t_list *scene, t_viewport *viewport, t_ray *ray)
{
	t_camera	*camera;
	t_color		*color;
	int			x;
	int			y;

	camera = (t_camera *)object_find("C", scene);
	color = color_create("0", "0", "0");
	if (camera != NULL && color != NULL)
	{
		x = -canva->width / 2;
		while (x <= canva->width / 2)
		{
			y = -canva->height / 2;
			while (y <= canva->height / 2)
			{
				ray_direction_set(ray, camera, &((t_vector) {x, y, 0}), viewport);
				ray_trace(color, ray, scene);
				canva_pixel_put(canva, x, y, trgb_create(0, color->red, color->green, color->blue));
				y++;
			}
			x++;
		}
	}
	if (color != NULL)
		color_free(color);
}
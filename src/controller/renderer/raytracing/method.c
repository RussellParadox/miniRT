/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 22:37:32 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 09:06:45 by gdornic          ###   ########.fr       */
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

t_vector	ray_point(t_ray ray, float parameter)
{
	return ((t_vector){ray.origin.x + parameter * ray.direction.x, \
	ray.origin.y + parameter * ray.direction.y, \
	ray.origin.z + parameter * ray.direction.z});
}

//ray = ray.origin + parameter * ray.direction
static t_color	ray_trace(t_ray ray, t_list *scene, int depth)
{
	t_closest	closest;
	t_vector	normal;
	t_color		local_color;
	t_color		reflect_color;
	float		r;

	closest = closest_intersection(ray, scene);
	if (closest.object == NULL)
		return ((t_color){0, 0, 0, 0});
	normal = object_normal(closest.object, \
	ray_point(ray, closest.parameter), ray.direction);
	local_color = light_effect(normal, scene, closest, ray);
	r = object_reflective(closest.object);
	if (depth <= 0 || r < 0 || r > 1)
		return (local_color);
	ray.origin = ray_point(ray, closest.parameter);
	ray.direction = vector_sub((t_vector){0, 0, 0}, ray.direction);
	ray.direction = reflection(normal, ray.direction);
	ray.parameter_min = PRECISION;
	reflect_color = ray_trace(ray, scene, depth - 1);
	return (reflective_color(local_color, reflect_color, r));
}

t_vector	ray_direction(t_vector base[3], float x, float y, float z)
{
	return ((t_vector){base[0].x * x + base[1].x * y + base[2].x * z, \
	base[0].y * x + base[1].y * y + base[2].y * z, \
	base[0].z * x + base[1].z * y + base[2].z * z});
}

void	raytracing_method(t_img *canva, t_list *scene, t_viewport viewport)
{
	t_camera	*camera;
	t_color		color;
	t_ray		ray;
	int			x;
	int			y;

	camera = (t_camera *)object_find("C", scene);
	color = (t_color){0, 0, 0, 0};
	ray.origin = *camera->coordinate;
	ray.parameter_min = CAM_VP_DIST;
	x = -canva->width / 2;
	while (x <= canva->width / 2)
	{
		y = -canva->height / 2;
		while (y <= canva->height / 2)
		{
			ray.direction = ray_direction(camera->base, x * \
			viewport.width_ratio, y * viewport.height_ratio, CAM_VP_DIST);
			color = ray_trace(ray, scene, 3);
			canva_pixel_put(canva, x, y, trgb_create(0, color.red, \
			color.green, color.blue));
			y++;
		}
		x++;
	}
}

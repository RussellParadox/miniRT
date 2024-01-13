/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:10:00 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/12 20:14:04 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	raytracing_render(t_img *canva, t_list *scene)
{
	t_viewport	*viewport;
	t_ray		*ray;
	t_camera	*camera;

	camera = (t_camera *)object_find("C", scene);
	viewport = viewport_create(canva, camera->fov * M_PI / 180, CAMERA_VIEWPORT_DISTANCE);
	ray = ray_create(camera->coordinate);
	if (viewport != NULL && ray != NULL)
		raytracing_method(canva, scene, viewport, ray);
	if (viewport != NULL)
		viewport_free(viewport);
	if (ray != NULL)
		ray_free(ray);
}
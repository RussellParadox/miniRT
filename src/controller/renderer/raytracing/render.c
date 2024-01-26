/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:10:00 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/25 09:53:48 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

//horizontal_fov in radians
t_viewport viewport_new(t_img *canva, float horizontal_fov, float distance)
{
	t_viewport	viewport;

	viewport.width = fabsf(2 * distance * tanf(horizontal_fov / 2));
	viewport.height = viewport.width / canva->ratio;
	viewport.width_ratio = viewport.width / canva->width;
	viewport.height_ratio = viewport.height / canva->height;
	return (viewport);
}

void	raytracing_render(t_img *canva, t_list *scene)
{
	t_viewport	viewport;
	t_camera	*camera;

	camera = (t_camera *)object_find("C", scene);
	viewport = viewport_new(canva, camera->fov * M_PI / 180, CAMERA_VIEWPORT_DISTANCE);
	raytracing_method(canva, scene, viewport);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:11:25 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/12 15:50:52 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

//horizontal_fov in radians
t_viewport *viewport_create(t_img *canva, float horizontal_fov, float distance)
{
	t_viewport	*viewport;

	viewport = malloc(sizeof(t_viewport));
	if (viewport == NULL)
		return (NULL);
	viewport->width = fabsf(2 * distance * tanf(horizontal_fov / 2));
	viewport->height = viewport->width / canva->ratio;
	viewport->width_ratio = viewport->width / canva->width;
	viewport->height_ratio = viewport->height / canva->height;
	return (viewport);
}
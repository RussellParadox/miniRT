/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:59:07 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/20 01:22:00 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	light_effect(t_color *color, t_list *scene, t_obj *object, t_vector *intersection)
{
	t_color		*obj_color;
	t_vector	intensity;

	obj_color = object_color(object);
	if (object == NULL)
	{
		color->red = obj_color->red;
		color->green = obj_color->green;
		color->blue = obj_color->blue;
		return ;
	}
	intensity.x = 0;
	intensity.y = 0;
	intensity.z = 0;
	light_intensity_model(&intensity, object, scene, intersection);
	color->red = obj_color->red * intensity.x;
	color->green = obj_color->green * intensity.y;
	color->blue = obj_color->blue * intensity.z;
	if (color->red > 255)
		color->red = 255;
	if (color->green > 255)
		color->green = 255;
	if (color->blue > 255)
		color->blue = 255;
}
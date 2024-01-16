/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 03:58:34 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/16 04:15:02 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	light_reflection(t_vector *intensity, t_vector *normal, t_light *light, t_vector *intersection)
{
	t_vector	l;
	float		weight;

	l.x = light->coordinate->x - intersection->x;
	l.y = light->coordinate->y - intersection->y;
	l.z = light->coordinate->z - intersection->z;
	weight = vector_scalar_product(&l, normal);
	if (weight < PRECISION)
		return ;
	weight /= (vector_norm(&l) * vector_norm(normal));
	intensity->x += weight * (light->ratio * light->color->red / light->color->sum);
	intensity->y += weight * (light->ratio * light->color->green / light->color->sum);
	intensity->z += weight * (light->ratio * light->color->blue / light->color->sum);
}
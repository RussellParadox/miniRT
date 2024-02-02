/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 05:31:02 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/02 18:30:40 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	plane_normal(t_plane *plane, t_vector d)
{
	t_vector	normal;

	normal = *plane->normal;
	normal = vector_normalized(normal);
	if (vector_scalar_product(normal, d) > 0)
	{
		normal = vector_sub((t_vector){0, 0, 0}, normal);
		*plane->normal = normal;
		//plane->base[0] = vector_sub((t_vector){0, 0, 0}, plane->base[0]);
		plane->base[1] = normal;
		//plane->base[2] = vector_sub((t_vector){0, 0, 0}, plane->base[2]);
	}
	return (normal);
}
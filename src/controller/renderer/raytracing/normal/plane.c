/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 05:31:02 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/28 14:31:49 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	plane_normal(t_plane *plane, t_vector d)
{
	t_vector	normal;

	normal = *plane->normal;
	normal = vector_normalized(normal);
	if (vector_scalar_product(normal, d) > 0)
		normal = vector_sub((t_vector){0, 0, 0}, normal);
	return (normal);
}
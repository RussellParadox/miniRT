/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:41:50 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/02 19:15:24 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	plane_bump(t_plane *plane, t_vector p)
{
	t_map		*map;
	t_color		color;
	t_vector	tbn[3];
	t_vector	bump;

	map = plane->normal_map;
	if (map == NULL)
		return ((t_vector){0, 0, 0});
	color = plane_mapping(plane, map, p);
	bump = (t_vector){2.0 * color.red / 255 - 1, 2.0 * color.green / 255 - 1, 2.0 * color.blue / 255 - 1};
	tbn[0] = plane->base[2];
	tbn[1] = plane->base[0];
	tbn[2] = plane->base[1];
	matrix_3x3_inverse(tbn);
	matrix_3x3_transpose(tbn);
	return (vector_normalized(vector_matrix_product(bump, tbn)));
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:41:09 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 10:12:05 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	sphere_bump(t_sphere *sphere, t_vector n)
{
	t_map		*map;
	t_color		color;
	t_vector	tbn[3];
	t_vector	bump;
	t_vector	local;

	map = sphere->normal_map;
	if (map == NULL)
		return ((t_vector){0, 0, 0});
	color = sphere_mapping(sphere, map, n);
	bump = (t_vector){2.0 * color.red / 255 - 1, \
	2.0 * color.green / 255 - 1, -2.0 * color.blue / 255 - 1};
	local.x = vector_scalar_product(n, sphere->base[0]);
	local.y = vector_scalar_product(n, sphere->base[1]);
	local.z = vector_scalar_product(n, sphere->base[2]);
	local = vector_normalized(local);
	tbn[0] = sphere_tangeant(sphere->diameter / 2, atan2f(local.z, \
	local.x), asinf(-local.y) + M_PI / 2);
	tbn[1] = vector_normalized(vector_cross_product(tbn[0], local));
	tbn[2] = local;
	matrix_3x3_inverse(tbn);
	matrix_3x3_transpose(tbn);
	return (vector_normalized(vector_matrix_product(bump, tbn)));
}

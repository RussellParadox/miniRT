/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:43:26 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/05 12:14:18 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	cylinder_bump(t_cylinder *cylinder, t_vector p, t_vector n)
{
	t_map		*map;
	t_color		color;
	t_vector	tbn[3];
	t_vector	bump;
	t_vector	local;
	t_vector	pc;

	map = cylinder->normal_map;
	if (map == NULL)
		return ((t_vector){0, 0, 0});
	color = cylinder_mapping(cylinder, map, p, n);
	bump = (t_vector){2.0 * color.red / 255 - 1, 2.0 * color.green / 255 - 1, -2.0 * color.blue / 255 - 1};
	pc = vector_sub(p, *cylinder->coordinate);
	local.x = vector_scalar_product(n, cylinder->base[0]);
	local.y = vector_scalar_product(n, cylinder->base[1]);
	local.z = vector_scalar_product(n, cylinder->base[2]);
	local = vector_normalized(local);
	tbn[0] = cylinder_tangeant(cylinder, pc, atan2f(local.z, local.x));
	tbn[1] = vector_normalized(vector_cross_product(tbn[0], local));
	tbn[2] = local;
	matrix_3x3_inverse(tbn);
	matrix_3x3_transpose(tbn);
	return (vector_normalized(vector_matrix_product(bump, tbn)));
}
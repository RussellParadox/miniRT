/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:47:39 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/03 18:04:17 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	cylinder_mapping(t_cylinder *cylinder, t_map *map, t_vector p, t_vector n)
{
	t_vector	pc;
	t_vector	local;
	int			u;
	int			v;

	pc = vector_sub(p, *cylinder->coordinate);
	if (2 * fabsf(vector_scalar_product(pc, *cylinder->axis)) + PRECISION > cylinder->height)
		n = vector_normalized(cylinder_height_normal(*cylinder->axis, pc, vector_scalar_product(pc, *cylinder->axis)));
	local.x = vector_scalar_product(n, cylinder->base[0]);
	local.y = vector_scalar_product(pc, cylinder->base[1]);
	local.z = vector_scalar_product(n, cylinder->base[2]);
	u = (atan2f(local.z, local.x) / (2 * M_PI) + 0.5) * (map->width - 1);
	v = (local.y / cylinder->height + 0.5) * (map->height - 1);
	return (map->color[u][v]);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:40:16 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/01 17:46:16 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	cylinder_color(t_cylinder *cylinder, t_vector p, t_vector n)
{
	t_vector	local;
	t_vector	pc;
	t_map		*map;
	int			u;
	int			v;

	map = cylinder->texture_map;
	if (map == NULL)
		return (*cylinder->color);
	pc = vector_sub(p, *cylinder->coordinate);
	if (2 * fabsf(vector_scalar_product(pc, *cylinder->axis)) + PRECISION > cylinder->height)
		n = vector_normalized(height_normal(*cylinder->axis, pc, vector_scalar_product(pc, *cylinder->axis)));
	local.x = vector_scalar_product(n, cylinder->base[0]);
	local.y = vector_scalar_product(pc, cylinder->base[1]);
	local.z = vector_scalar_product(n, cylinder->base[2]);
	u = (atan2f(local.z, local.x) / (2 * M_PI) + 0.5) * (map->width - 1);
	v = (local.y / cylinder->height + 0.5) * (map->height - 1);
	return (map->color[u][v]);
}
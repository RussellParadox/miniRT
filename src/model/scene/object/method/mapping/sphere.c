/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:41:29 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 10:14:01 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	sphere_mapping(t_sphere *sphere, t_map *map, t_vector n)
{
	t_vector	local;
	int			u;
	int			v;

	local.x = vector_scalar_product(n, sphere->base[0]);
	local.y = vector_scalar_product(n, sphere->base[1]);
	local.z = vector_scalar_product(n, sphere->base[2]);
	u = (atan2f(local.z, local.x) / (2 * M_PI) + 0.5) * (map->width - 1);
	v = (asinf(-local.y) / M_PI + 0.5) * (map->height - 1);
	return (map->color[u][v]);
}

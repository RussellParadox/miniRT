/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:39:04 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/01 12:32:07 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	sphere_color(t_sphere *sphere, t_vector n)
{
	t_map	    *map;
	t_vector	local;
	int		    u;
	int		    v;

	map = sphere->texture_map;
	if (map == NULL)
		return (*sphere->color);
	local.x = vector_scalar_product(n, sphere->base[0]);
	local.y = vector_scalar_product(n, sphere->base[1]);
	local.z = vector_scalar_product(n, sphere->base[2]);
	u = (atan2f(local.z, local.x) / (2 * M_PI) + 0.5) * (map->width - 1);
	v = (asinf(-local.y) / M_PI + 0.5) * (map->height - 1);
	return (map->color[u][v]);
}
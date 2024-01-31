/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:39:04 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/31 13:57:32 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	sphere_color(t_sphere *sphere, t_vector n)
{
	t_map	*map;
	int		u;
	int		v;

	map = sphere->texture_map;
	if (map == NULL)
		return (*sphere->color);
	u = (atan2f(n.z, n.x) / (2 * M_PI) + 0.5) * (map->width - 1);
	v = (asinf(-n.y) / M_PI + 0.5) * (map->height - 1);
	return (map->color[u][v]);
}
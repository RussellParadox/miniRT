/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:39:04 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/02 14:44:57 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	sphere_color(t_sphere *sphere, t_vector n)
{
	t_map	    *map;

	map = sphere->texture_map;
	if (map == NULL)
		return (*sphere->color);
	return (sphere_mapping(sphere, map, n));
}
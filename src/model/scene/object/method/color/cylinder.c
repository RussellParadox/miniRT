/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:40:16 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/02 14:51:55 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	cylinder_color(t_cylinder *cylinder, t_vector p, t_vector n)
{
	t_map		*map;

	map = cylinder->texture_map;
	if (map == NULL)
		return (*cylinder->color);
	return (cylinder_mapping(cylinder, map, p, n));
}
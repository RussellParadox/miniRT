/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 05:31:02 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/25 10:19:01 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	plane_normal(t_plane *plane)
{
	t_vector	normal;
	float		norm;

	normal.x = plane->normal->x;
	normal.y = plane->normal->y;
	normal.z = plane->normal->z;
	norm = vector_norm(normal);
	normal.x /= norm;
	normal.y /= norm;
	normal.z /= norm;
	return (normal);
}
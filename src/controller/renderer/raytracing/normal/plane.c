/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 05:31:02 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/17 05:35:51 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	plane_normal(t_vector *normal, t_plane *plane)
{
	float	norm;

	normal->x = plane->normal->x;
	normal->y = plane->normal->y;
	normal->z = plane->normal->z;
	norm = vector_norm(normal);
	normal->x /= norm;
	normal->y /= norm;
	normal->z /= norm;
}
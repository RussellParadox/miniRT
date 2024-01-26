/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 04:23:49 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/25 10:19:59 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	sphere_normal(t_sphere *sphere, t_vector intersection)
{
	t_vector	normal;
	float		norm;

	normal.x = intersection.x - sphere->coordinate->x;
	normal.y = intersection.y - sphere->coordinate->y;
	normal.z = intersection.z - sphere->coordinate->z;
	norm = vector_norm(normal);
	normal.x /= norm;
	normal.y /= norm;
	normal.z /= norm;
	return (normal);
}
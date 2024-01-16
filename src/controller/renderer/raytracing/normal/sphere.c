/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 04:23:49 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/16 04:26:46 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	sphere_normal(t_vector *normal, t_sphere *sphere, t_vector *intersection)
{
	float	norm;

	normal->x = intersection->x - sphere->coordinate->x;
	normal->y = intersection->y - sphere->coordinate->y;
	normal->z = intersection->z - sphere->coordinate->z;
	norm = vector_norm(normal);
	normal->x /= norm;
	normal->y /= norm;
	normal->z /= norm;
}
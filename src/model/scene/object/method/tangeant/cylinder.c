/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:46:03 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/05 12:12:26 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	cylinder_disc_tangeant(t_vector axis, t_vector pc)
{
	return (vector_normalized(cylinder_height_normal(axis, pc, \
	vector_scalar_product(pc, axis))));
}

t_vector	cylinder_height_tangeant(float r, float theta)
{
	return (vector_normalized((t_vector){-r * sinf(theta), \
	0, \
	r * cosf(theta)}));
}

t_vector	cylinder_tangeant(t_cylinder *cylinder, t_vector pc, float theta)
{
	if (2 * fabsf(vector_scalar_product(pc, *cylinder->axis)) + PRECISION > cylinder->height)
		return (cylinder_disc_tangeant(*cylinder->axis, pc));
	return (cylinder_height_tangeant(cylinder->diameter / 2, theta));
}
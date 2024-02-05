/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:46:03 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/03 18:42:29 by gdornic          ###   ########.fr       */
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_of_basis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:54:17 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/31 17:53:14 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void		transition_update(t_vector transition[3], t_vector base[3])
{
	transition[0] = base[0];
	transition[1] = base[1];
	transition[2] = base[2];
	matrix_3x3_inverse(transition);
}

t_vector	change_of_basis(t_vector v, t_vector transition[3])
{
	return ((t_vector){v.x * transition[0].x + v.y * transition[1].x + v.z * transition[2].x, \
	v.x * transition[0].y + v.y * transition[1].y + v.z * transition[2].y, \
	v.x * transition[0].z + v.y * transition[1].z + v.z * transition[2].z});
}
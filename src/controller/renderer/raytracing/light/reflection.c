/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:25:50 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/25 16:26:11 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	reflection(t_vector normal, t_vector d)
{
	t_vector	r;
	float		n_dot_d;

	n_dot_d = vector_scalar_product(d, normal);
	r.x = 2 * n_dot_d * normal.x - d.x;
	r.y = 2 * n_dot_d * normal.y - d.y;
	r.z = 2 * n_dot_d * normal.z - d.z;
	return (r);
}

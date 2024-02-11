/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_product.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:54:17 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 08:58:09 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	vector_matrix_product(t_vector v, t_vector m[3])
{
	return ((t_vector){v.x * m[0].x + v.y * m[1].x + v.z * m[2].x, \
	v.x * m[0].y + v.y * m[1].y + v.z * m[2].y, \
	v.x * m[0].z + v.y * m[1].z + v.z * m[2].z});
}

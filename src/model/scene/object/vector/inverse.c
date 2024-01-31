/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:51:26 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/31 16:44:21 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static float	determinant_3x3(t_vector m[3])
{
	return (m[0].x * m[1].y * m[2].z \
	+ m[0].y * m[1].z * m[2].x \
	+ m[0].z * m[1].x * m[2].y \
	- m[0].z * m[1].y * m[2].x \
	- m[0].y * m[1].x * m[2].z \
	- m[0].x * m[1].z * m[2].y);
}

void	matrix_3x3_inverse(t_vector m[3])
{
	float	det_inv;

	det_inv = 1 / determinant_3x3(m);
	m[0].x = det_inv * (m[1].y * m[2].z - m[1].z * m[2].y);
	m[0].y = det_inv * (m[1].z * m[2].x - m[1].x * m[2].z);
	m[0].z = det_inv * (m[1].x * m[2].y - m[1].y * m[2].x);
	m[1].x = det_inv * (m[0].z * m[2].y - m[0].y * m[2].z);
	m[1].y = det_inv * (m[0].x * m[2].z - m[0].z * m[2].x);
	m[1].z = det_inv * (m[0].y * m[2].x - m[0].x * m[2].y);
	m[2].x = det_inv * (m[0].y * m[1].z - m[0].z * m[1].y);
	m[2].y = det_inv * (m[0].z * m[1].x - m[0].x * m[1].x);
	m[2].z = det_inv * (m[0].x * m[1].y - m[0].y * m[1].x);
}
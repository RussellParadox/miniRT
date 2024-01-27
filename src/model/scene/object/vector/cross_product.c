/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_product.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:48:30 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/27 16:58:33 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	vector_cross_product(t_vector v1, t_vector v2)
{
	/*
	return ((t_vector){v1.x * v2.z - v2.x * v1.z, \
	v1.z * v2.y - v2.z * v1.y, \
	v1.y * v2.x - v2.y * v1.x});
	return ((t_vector){v1.y * v2.z - v2.y * v1.z, \
	v1.z * v2.x - v2.z * v1.x, \
	v1.x * v2.y - v2.x * v1.y});
	*/
	return ((t_vector){v2.y * v1.z - v1.y * v2.z, \
	v2.z * v1.x - v1.z * v2.x, \
	v2.x * v1.y - v1.x * v2.y});
}
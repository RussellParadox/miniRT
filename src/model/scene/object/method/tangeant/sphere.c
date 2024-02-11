/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:23:13 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 08:57:20 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	sphere_tangeant(float r, float theta, float phi)
{
	return (vector_normalized((t_vector){-r * sinf(phi) * sinf(theta), \
	0, \
	r * sinf(phi) * cosf(theta)}));
}

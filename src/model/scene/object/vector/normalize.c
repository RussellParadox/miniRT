/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:59:10 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/27 15:00:40 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	vector_normalized(t_vector v)
{
	float	norm;

	norm = vector_norm(v);
	v.x /= norm;
	v.y /= norm;
	v.z /= norm;
	return (v);
}
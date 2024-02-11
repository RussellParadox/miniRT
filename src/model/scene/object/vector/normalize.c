/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:59:10 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 10:59:32 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	vector_normalized(t_vector v)
{
	float	norm;

	norm = vector_norm(v);
	if (norm < 0.0001)
	{
		v.x = 0;
		v.y = 0;
		v.z = 1;
	}
	else
	{
		v.x /= norm;
		v.y /= norm;
		v.z /= norm;
	}
	return (v);
}

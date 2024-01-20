/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic_minimum.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:01:50 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/20 00:30:49 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	intersection_quadratic_minimum(register float a, register float b, register float c)
{
	float	parameter1;
	float	parameter2;
	float	delta;

	delta = powf(b, 2) - 4 * a * c;
	if (delta < 0)
		return (FLT_MAX);
	delta = sqrtf(delta);
	parameter1 = (-b - delta) / (2 * a);
	parameter2 = (-b + delta) / (2 * a);
	if (parameter1 < parameter2 && parameter1 > CAMERA_VIEWPORT_DISTANCE)
		return (parameter1);
	else
		return (parameter2);
}
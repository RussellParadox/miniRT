/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic_minimum.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:01:50 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/14 19:05:55 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	intersection_quadratic_minimum(float a, float b, float c)
{
	float	parameter1;
	float	parameter2;
	float	delta;

	delta = powf(b, 2) - 4 * a * c;
	if (delta < 0)
		return (FLT_MAX);
	parameter1 = (-b - sqrtf(delta)) / (2 * a);
	parameter2 = (-b + sqrtf(delta)) / (2 * a);
	if (parameter1 < parameter2 && parameter1 > CAMERA_VIEWPORT_DISTANCE)
		return (parameter1);
	else
		return (parameter2);
}
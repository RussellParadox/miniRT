/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:53:43 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/10 18:01:57 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	light_rule(char **data)
{
	int		data_len;
	float	ratio;

	data_len = split_len(data);
	if (data_len != 4)
		return (put_error("Light: wrong information quantity"));
	if (vector_rule(data[1]))
		return (put_error("Light: coordinate: wrong vector format"));
	if (float_rule(data[2]))
		return (put_error("Light: ratio: wrong float format"));
	ratio = ascii_to_float(data[2]);
	if (ratio < 0.0 + PRECISION || ratio > 1.0 + PRECISION)
		return (put_error("Light: ratio: outside allowed range"));
	if (rgb_rule(data[3]))
		return (put_error("Light: color: wrong RGB format"));
	return (0);
}
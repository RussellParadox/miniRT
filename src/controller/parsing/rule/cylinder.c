/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:28:20 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 08:49:33 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	cylinder_rule(char **data)
{
	int	data_len;

	data_len = split_len(data);
	if (data_len < 6 || data_len > 10)
		return (put_error("Cylinder: wrong information quantity"));
	if (vector_rule(data[1]))
		return (put_error("Cylinder: coordinate: wrong vector format"));
	if (vector_normalized_rule(data[2]))
		return (put_error("Cylinder: axis: wrong normalized vector format"));
	if (float_rule(data[3]))
		return (put_error("Cylinder: diameter: wrong float format"));
	if (float_rule(data[4]))
		return (put_error("Cylinder: cylinder: wrong float format"));
	if (rgb_rule(data[5]))
		return (put_error("Cylinder: color: wrong RGB format"));
	return (0);
}

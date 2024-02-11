/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:53:57 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 08:50:08 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	sphere_rule(char **data)
{
	int	data_len;

	data_len = split_len(data);
	if (data_len < 4 || data_len > 8)
		return (put_error("Sphere: wrong information quantity"));
	if (vector_rule(data[1]))
		return (put_error("Sphere: coordinate: wrong vector format"));
	if (float_rule(data[2]))
		return (put_error("Sphere: diameter: wrong float format"));
	if (rgb_rule(data[3]))
		return (put_error("Sphere: color: wrong RGB format"));
	return (0);
}

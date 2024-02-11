/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:28:07 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 08:50:00 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	plane_rule(char **data)
{
	int	data_len;

	data_len = split_len(data);
	if (data_len < 4 || data_len > 8)
		return (put_error("Plane: wrong information quantity"));
	if (vector_rule(data[1]))
		return (put_error("Plane: coordinate: wrong vector format"));
	if (vector_normalized_rule(data[2]))
		return (put_error("Plane: normal: wrong normalized vector format"));
	if (rgb_rule(data[3]))
		return (put_error("Plane: color: wrong RGB format"));
	return (0);
}

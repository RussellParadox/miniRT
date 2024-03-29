/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:52:48 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 09:02:24 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	camera_rule(char **data)
{
	static int	c_count = 0;
	int			data_len;
	int			fov;

	c_count++;
	if (c_count > 1)
		return (put_error("Too many Camera"));
	data_len = split_len(data);
	if (data_len != 4)
		return (put_error("Camera: wrong information quantity"));
	if (vector_rule(data[1]))
		return (put_error("Camera: coordinate: wrong vector format"));
	if (vector_normalized_rule(data[2]))
		return (put_error("Camera: orientation: wrong normalized \
		vector format"));
	if (int_rule(data[3]))
		return (put_error("Camera: fov: wrong int format"));
	fov = ft_atoi(data[3]);
	if (fov < 0 || fov > 180)
		return (put_error("Camera: fov: outside allowed range"));
	return (0);
}

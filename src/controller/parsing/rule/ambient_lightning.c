/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_lightning.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:52:04 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/10 15:34:05 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ambient_lightning_rule(char **data)
{
	static int	A_count = 0;
	int			data_len;
	float		ratio;

	A_count++;
	if (A_count > 1)
		return (put_error("Too many Ambient lightning"));
	data_len = split_len(data);
	if (data_len != 3)
		return (put_error("Ambient lightning: wrong information quantity"));
	if (float_rule(data[1]))
		return (put_error("Ambient lightning: ratio: wrong float format"));
	ratio = ascii_to_float(data[1]);
	if (ratio < 0.0 + PRECISION || ratio > 1.0 + PRECISION)
		return (put_error("Ambient lightning: ratio: outside allowed range"));
	if (rgb_rule(data[2]))
		return (put_error("Ambient lightning: color: wrong RGB format"));
	return (0);
}
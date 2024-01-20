/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:58:21 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/19 23:41:57 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	draw_circle(t_img *canva, int origin_x, int origin_y, int radius)
{
	int	thickness;
	int	x;
	int	y;

	thickness = 10;
	x = -canva->width / 2;
	while (x < canva->width / 2)
	{
		y = -canva->height / 2;
		while (y < canva->height / 2)
		{
			if (pow(x - origin_x, 2) + pow(y - origin_y, 2) <= pow(radius + thickness / 2, 2) && pow(x - origin_x, 2) + pow(y - origin_y, 2) >= pow(radius - thickness / 2, 2))
				canva_pixel_put(canva, x, y, trgb_create(255, 255, 0, 0));
			y++;
		}
		x++;
	}
}
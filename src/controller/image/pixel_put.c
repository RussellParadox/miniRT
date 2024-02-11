/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 23:50:45 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 10:05:23 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	image_pixel_put(t_img *image, int x, int y, int color)
{
	unsigned int	*pixel;

	pixel = (unsigned int *)(image->addr + (y * image->line_length + \
	x * (image->bits_per_pixel / 8)));
	*pixel = color;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 23:36:51 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 10:05:12 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_img	*image_create(t_mlx *mlx, int width, int height)
{
	t_img	*image;

	image = malloc(sizeof(t_img));
	if (image == NULL)
		return (NULL);
	image->instance = mlx_new_image(mlx->instance, width, height);
	if (image->instance == NULL)
	{
		free(image);
		return (NULL);
	}
	image->addr = mlx_get_data_addr(image->instance, \
	&image->bits_per_pixel, &image->line_length, &image->endian);
	image->width = width;
	image->height = height;
	image->ratio = (float)width / height;
	return (image);
}

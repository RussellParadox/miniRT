/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:26:59 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/04 09:31:21 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	image_free(t_img *image, t_mlx *mlx)
{
	mlx_destroy_image(mlx->instance, image->instance);
	free(image);
}
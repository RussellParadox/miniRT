/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 23:28:39 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 08:58:47 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	view_routine(t_img *image, t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->instance, mlx->window, image->instance, 0, 0);
}

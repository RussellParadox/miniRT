/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 00:18:51 by gdornic           #+#    #+#             */
/*   Updated: 2023/12/31 00:24:18 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	canva_pixel_put(t_img *canva, int x, int y, int color)
{
	image_pixel_put(canva, canva->width / 2 + x, canva->height / 2 - y, color);
}
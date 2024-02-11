/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_lightning.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 02:53:37 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 09:19:28 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	ambient_lightning_intensity(t_ambient_lightning *ambient_lightning)
{
	return ((t_vector){ambient_lightning->ratio * \
	ambient_lightning->color->red / ambient_lightning->color->sum, \
	ambient_lightning->ratio * \
	ambient_lightning->color->green / ambient_lightning->color->sum, \
	ambient_lightning->ratio * \
	ambient_lightning->color->blue / ambient_lightning->color->sum});
}

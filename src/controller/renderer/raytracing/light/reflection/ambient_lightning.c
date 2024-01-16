/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_lightning.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 02:53:37 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/16 03:45:40 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ambient_lightning_reflection(t_vector *intensity, t_ambient_lightning *ambient_lightning)
{
	intensity->x += ambient_lightning->ratio * ambient_lightning->color->red / ambient_lightning->color->sum;
	intensity->y += ambient_lightning->ratio * ambient_lightning->color->green / ambient_lightning->color->sum;
	intensity->z += ambient_lightning->ratio * ambient_lightning->color->blue / ambient_lightning->color->sum;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:18:07 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 08:55:17 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	*ambient_lightning_free(t_ambient_lightning *ambient_lightning)
{
	if (ambient_lightning->color != NULL)
		color_free(ambient_lightning->color);
	free(ambient_lightning);
	return (NULL);
}

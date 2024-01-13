/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:41:18 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/12 20:04:49 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	*ray_free(t_ray	*ray)
{
	if (ray->origin != NULL)
		vector_free(ray->origin);
	if (ray->direction != NULL)
		vector_free(ray->direction);
	free(ray);
	return (NULL);
}
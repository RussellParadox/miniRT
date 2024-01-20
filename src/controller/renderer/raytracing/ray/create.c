/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:38:25 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/20 05:13:03 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	ray_init(t_ray *ray, t_vector *coordinate)
{
	ray->origin = vector_create("0", "0", "0");
	if (ray->origin == NULL)
		return ;
	ray->origin->x = coordinate->x;
	ray->origin->y = coordinate->y;
	ray->origin->z = coordinate->z;
	ray->direction = vector_create("0", "0", "0");
	if (ray->direction == NULL)
		return ;
}

t_ray	*ray_create(t_vector *coordinate)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (ray == NULL)
		return (NULL);
	ray->origin = NULL;
	ray->direction = NULL;
	ray_init(ray, coordinate);
	if (errno == ENOMEM)
		return (ray_free(ray));
	return (ray);
}
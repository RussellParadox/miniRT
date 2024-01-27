/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 05:31:02 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/27 16:17:10 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	plane_normal(t_plane *plane)
{
	t_vector	normal;

	normal = *plane->normal;
	normal = vector_normalized(normal);
	return (normal);
}
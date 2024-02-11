/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 04:23:49 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 08:57:13 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	sphere_normal(t_sphere *sphere, t_vector intersection)
{
	t_vector	normal;

	normal = vector_sub(intersection, *sphere->coordinate);
	normal = vector_normalized(normal);
	return (normal);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:58:50 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/02 17:00:00 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	*sphere_free(t_sphere *sphere)
{
	if (sphere->coordinate != NULL)
		vector_free(sphere->coordinate);
	if (sphere->color != NULL)
		color_free(sphere->color);
	free(sphere);
	return (NULL);
}
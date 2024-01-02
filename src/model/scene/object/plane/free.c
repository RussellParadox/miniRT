/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:50:35 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/02 16:52:01 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	*plane_free(t_plane *plane)
{
	if (plane->coordinate != NULL)
		vector_free(plane->coordinate);
	if (plane->normal != NULL)
		vector_free(plane->normal);
	if (plane->color != NULL)
		color_free(plane->color);
	free(plane);
	return (NULL);
}
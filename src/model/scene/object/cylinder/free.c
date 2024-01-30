/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:07:55 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/29 16:18:26 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	*cylinder_free(t_cylinder *cylinder)
{
	if (cylinder->coordinate != NULL)
		vector_free(cylinder->coordinate);
	if (cylinder->axis != NULL)
		vector_free(cylinder->axis);
	if (cylinder->color != NULL)
		color_free(cylinder->color);
	if (cylinder->texture_map != NULL)
		map_free(cylinder->texture_map);
	free(cylinder);
	return (NULL);
}
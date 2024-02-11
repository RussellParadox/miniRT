/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:53:31 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 08:55:32 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	*camera_free(t_camera *camera)
{
	if (camera->coordinate != NULL)
		vector_free(camera->coordinate);
	if (camera->orientation != NULL)
		vector_free(camera->orientation);
	free(camera);
	return (NULL);
}

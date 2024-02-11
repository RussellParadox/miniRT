/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:40:35 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 08:47:27 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_mlx	*mlx_create(int width, int height, char *name)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (mlx == NULL)
		return (NULL);
	mlx->instance = mlx_init();
	if (mlx->instance == NULL)
	{
		free(mlx);
		return (NULL);
	}
	mlx->window = mlx_new_window(mlx->instance, width, height, name);
	return (mlx);
}

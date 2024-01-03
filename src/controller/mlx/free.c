/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:12:43 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/03 22:17:13 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	*mlx_free(t_mlx *mlx)
{
	mlx_destroy_window(mlx->instance, mlx->window);
	mlx_destroy_display(mlx->instance);
	free(mlx->instance);
	free(mlx);
	return (NULL);
}
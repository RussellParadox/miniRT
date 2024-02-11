/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:40:59 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 08:47:12 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

//loop on events hooks
int	controller_loop(t_list	*scene)
{
	t_mlx	*mlx;

	mlx = mlx_create(WINDOW_WIDTH, WINDOW_HEIGHT, "miniRT");
	if (mlx == NULL)
		return (EXIT_FAILURE);
	hook_routine(mlx, scene);
	mlx_loop(mlx->instance);
	mlx_free(mlx);
	return (EXIT_SUCCESS);
}

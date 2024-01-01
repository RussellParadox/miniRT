/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:40:59 by gdornic           #+#    #+#             */
/*   Updated: 2023/12/31 22:59:27 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

//loop on events hooks
int	controller_loop(t_list	*scene)
{
	t_mlx	*mlx;

	mlx = mlx_create();
	if (mlx == NULL)
		return (EXIT_FAILURE);
	hook_routine(mlx, scene);
	mlx_loop(mlx->instance);
	mlx_free(mlx);
	return (EXIT_SUCCESS);
}
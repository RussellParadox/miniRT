/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:40:59 by gdornic           #+#    #+#             */
/*   Updated: 2023/12/29 16:52:45 by gdornic          ###   ########.fr       */
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
	events_hooks(mlx, scene);
	mlx_loop(mlx->instance);
	mlx_free(mlx);
	return (EXIT_SUCCESS);
}
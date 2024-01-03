/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:43:56 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/03 23:00:56 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	hook_routine(t_mlx *mlx, t_list *scene)
{
	void	*param[2];

	param[0] = mlx;
	param[1] = scene;
	mlx_hook(mlx->window, ON_DESTROY, (0L), &loop_end_hook, param);
	mlx_loop_hook(mlx->instance, &controller_routine, param);
}
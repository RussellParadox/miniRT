/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:43:56 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 08:48:04 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	hook_routine(t_mlx *mlx, t_list *scene)
{
	static void	*param[2];

	param[0] = mlx;
	param[1] = scene;
	mlx_hook(mlx->window, 17, (0L), &loop_end_hook, param);
	mlx_key_hook(mlx->window, key_hook, param);
	mlx_loop_hook(mlx->instance, &controller_routine, param);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:55:10 by gdornic           #+#    #+#             */
/*   Updated: 2023/12/30 22:52:25 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	events_hooks(t_mlx *mlx, t_list *scene)
{
	void	*param[2];

	param[0] = mlx;
	param[1] = scene;
	mlx_loop_hook(mlx->instance, &controller_routine, param);
}
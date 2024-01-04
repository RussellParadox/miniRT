/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:54:02 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/04 09:40:48 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	loop_end_hook(void *param[2])
{
	t_mlx	*mlx;

	mlx = param[0];
	mlx_loop_end(mlx->instance);
	return (0);
}
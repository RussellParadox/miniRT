/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 07:56:32 by gdornic           #+#    #+#             */
/*   Updated: 2023/12/31 00:24:44 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef miniRT_H
# define miniRT_H
# include <get_next_line.h>
# include <libft.h>
# include <libftprintf.h>
# include <mlx.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>

/*controller*/
//loop
int		controller_loop(t_list	*scene);

//events hooks
void	events_hooks(t_mlx *mlx, t_list *scene);

//routine
int		controller_routine(void *param[2]);

/*model*/
/*->canva*/
void	canva_pixel_put(t_img *canva, int x, int y, int color);

/*->image*/
//pixel put
void	image_pixel_put(t_img *image, int x, int y, int color);

/*->scene*/

/*view*/

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 07:56:32 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/01 01:12:27 by gdornic          ###   ########.fr       */
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

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;

/*controller*/
//loop
int		controller_loop(t_list	*scene);

//routine
int		controller_routine(void *param[2]);

/*->canva*/
void	canva_pixel_put(t_img *canva, int x, int y, int color);

/*->image*/
//pixel put
void	image_pixel_put(t_img *image, int x, int y, int color);

/*->hook*/
//routine
void	hook_routine(t_mlx *mlx, t_list *scene);

/*model*/
/*->scene*/
typedef struct s_ambient_lightning
{
	float	ratio;
	t_color	*color;
}	t_ambient_lightning;

typedef struct s_camera
{
	t_vector	*coordinate;
	t_vector	*orientation;
	float		fov;
}	t_camera;

typedef struct s_light
{
	t_vector	*coordinate;
	float		ratio;
	t_color		*color;
}	t_light;

typedef struct s_sphere
{
	t_vector	*coordinate;
	float		diameter;
	t_color		*color;
}	t_sphere;

typedef struct s_plane
{
	t_vector	*coordinate;
	t_vector	*normal;
	t_color		*color;
}	t_plane;

typedef struct s_cylinder
{
	t_vector	*coordinate;
	t_vector	*axis_normal;
	float		diameter;
	float		height;
	t_color		*color;
}	t_cylinder;

typedef struct s_obj
{
	int	id;
	union
	{
		t_ambient_lightning	*ambient_lightning;
		t_camera			*camera;
		t_light				*light;
		t_sphere			*sphere;
		t_plane				*plane;
		t_cylinder			*cylinder;
	};
}	t_obj;

t_list	*scene_create(int fd);

/*view*/

#endif
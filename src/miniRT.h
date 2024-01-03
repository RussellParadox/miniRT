/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 07:56:32 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/03 23:01:38 by gdornic          ###   ########.fr       */
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
# include <toolbox.h>

/*controller*/
//loop
int		controller_loop(t_list	*scene);
//routine
int		controller_routine(void *param[2]);
/*->mlx*/
typedef struct s_mlx
{
	void	*instance;
	void	*window;
}	t_mlx;
//create
t_mlx	*mlx_create(int width, int height, char *name);
//free
void	*mlx_free(t_mlx *mlx);

/*->canva*/
void	canva_pixel_put(t_img *canva, int x, int y, int color);

/*->image*/
//pixel put
void	image_pixel_put(t_img *image, int x, int y, int color);

/*->hook*/
//routine
void	hook_routine(t_mlx *mlx, t_list *scene);
//loop end
int	loop_end_hook(void *param[2]);

/*model*/
/*->scene*/
//create
t_list	*scene_create(int fd);
//free
void	*scene_free(t_list *scene);

/*->->vector*/
typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;
//create
t_vector	*vector_create(char *x, char *y, char *z);
//free
void	*vector_free(t_vector *vector);

/*->->color*/
typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;
//create
t_color	*color_create(char *red, char *green, char *blue);
//free
void	*color_free(t_color *color);

/*->->->ambient_lightning*/
typedef struct s_ambient_lightning
{
	float	ratio;
	t_color	*color;
}	t_ambient_lightning;
//create
t_ambient_lightning	*ambient_lightning_create(char **data);
//free
void	*ambient_lightning_free(t_ambient_lightning *ambient_lightning);

/*->->->camera*/
typedef struct s_camera
{
	t_vector	*coordinate;
	t_vector	*orientation;
	float		fov;
}	t_camera;
//create
t_camera	*camera_create(char **data);
//free
void	*camera_free(t_camera *camera);

/*->->->light*/
typedef struct s_light
{
	t_vector	*coordinate;
	float		ratio;
	t_color		*color;
}	t_light;
//create
t_light	*light_create(char **data);
//free
void	*light_free(t_light *light);

/*->->->sphere*/
typedef struct s_sphere
{
	t_vector	*coordinate;
	float		diameter;
	t_color		*color;
}	t_sphere;
//create
t_sphere	*sphere_create(char **data);
//free
void	*sphere_free(t_sphere *sphere);

/*->->->plane*/
typedef struct s_plane
{
	t_vector	*coordinate;
	t_vector	*normal;
	t_color		*color;
}	t_plane;
//create
t_plane	*plane_create(char **data);
//free
void	*plane_free(t_plane *plane);

/*->->->cylinder*/
typedef struct s_cylinder
{
	t_vector	*coordinate;
	t_vector	*axis_normal;
	float		diameter;
	float		height;
	t_color		*color;
}	t_cylinder;
//create
t_cylinder	*cylinder_create(char **data);
//free
void	*cylinder_free(t_cylinder *cylinder);

/*->->object*/
# define ID_LEN_MAX 100
typedef struct s_obj
{
	char	id[ID_LEN_MAX];
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
//next object
t_obj	*next_object(int fd);
//create
t_obj	*object_create(char **data);
//free
void	*object_free(t_obj *object);

/*view*/

#endif
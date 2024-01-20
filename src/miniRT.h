/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 07:56:32 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/20 03:03:05 by gdornic          ###   ########.fr       */
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
# include <float.h>

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

typedef struct s_color
{
	int		red;
	int		green;
	int		blue;
	float	sum;
}	t_color;

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
	float		specular;
}	t_sphere;

typedef struct s_plane
{
	t_vector	*coordinate;
	t_vector	*normal;
	t_color		*color;
	float		specular;
}	t_plane;

typedef struct s_cylinder
{
	t_vector	*coordinate;
	t_vector	*axis;
	float		diameter;
	float		height;
	t_color		*color;
	float		specular;
}	t_cylinder;

typedef struct u_obj_type
{
	t_ambient_lightning	*ambient_lightning;
	t_camera			*camera;
	t_light				*light;
	t_sphere			*sphere;
	t_plane				*plane;
	t_cylinder			*cylinder;
}	t_obj_type;
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

# define WINDOW_WIDTH 700
# define WINDOW_HEIGHT 700
typedef struct s_mlx
{
	void	*instance;
	void	*window;
}	t_mlx;

typedef struct s_img
{
	void	*instance;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	float	ratio;
}	t_img;

typedef struct s_ray
{
	t_vector	*origin;
	t_vector	*direction;
}	t_ray;

typedef struct s_viewport
{
	float	width;
	float	height;
	float	width_ratio;
	float	height_ratio;
}	t_viewport;

/*model*/

/*->scene*/
//create
t_list	*scene_create(int fd);
//free
void	*scene_free(t_list *scene);

/*->->object*/

/*->->->vector*/
//create
void	vector_init(t_vector *vector, float x, float y, float z);
t_vector	*vector_create(char *x, char *y, char *z);
//free
void	*vector_free(t_vector *vector);
//scalar product
float	vector_scalar_product(t_vector *v1, t_vector *v2);
//norm
float	vector_norm(t_vector *v);

/*->->->color*/
//create
t_color	*color_create(char *red, char *green, char *blue);
//free
void	*color_free(t_color *color);

/*->->->ambient_lightning*/
//create
t_ambient_lightning	*ambient_lightning_create(char **data);
//free
void	*ambient_lightning_free(t_ambient_lightning *ambient_lightning);

/*->->->camera*/
//create
t_camera	*camera_create(char **data);
//free
void	*camera_free(t_camera *camera);

/*->->->light*/
//create
t_light	*light_create(char **data);
//free
void	*light_free(t_light *light);

/*->->->sphere*/
//create
t_sphere	*sphere_create(char **data);
//free
void	*sphere_free(t_sphere *sphere);

/*->->->plane*/
//create
t_plane	*plane_create(char **data);
//free
void	*plane_free(t_plane *plane);

/*->->->cylinder*/
//create
t_cylinder	*cylinder_create(char **data);
//free
void	*cylinder_free(t_cylinder *cylinder);

//ratio method
float	object_ratio(t_obj *object);
//specular method
float	object_specular(t_obj *object);
//color method
t_color	*object_color(t_obj *object);
//find method
t_obj_type	*object_find(char *id, t_list *scene);
//next object
t_obj	*next_object(int fd);
//create
t_obj	*object_create(char **data);
//free
void	object_free(void *content);

/*view*/
//routine
void	view_routine(t_img *image, t_mlx *mlx);

/*controller*/
//loop
int		controller_loop(t_list	*scene);
//routine
int		controller_routine(void *param[2]);

/*->mlx*/
//create
t_mlx	*mlx_create(int width, int height, char *name);
//free
void	*mlx_free(t_mlx *mlx);

/*->image*/
//create
t_img	*image_create(t_mlx *mlx, int width, int height);
//free
void	image_free(t_img *image, t_mlx *mlx);
//pixel put
void	image_pixel_put(t_img *image, int x, int y, int color);

/*->color_trgb*/
//create
int	trgb_create(int t, int r, int g, int b);

/*->canva*/
void	canva_pixel_put(t_img *canva, int x, int y, int color);

/*->hook*/
//routine
void	hook_routine(t_mlx *mlx, t_list *scene);
//loop end
int	loop_end_hook(void *param[2]);

/*->renderer*/
//draw circle
void	draw_circle(t_img *canva, int origin_x, int origin_y, int radius);

/*->->raytracing*/

/*->->->ray*/
//create
t_ray	*ray_create(t_vector *coordinate);
//free
void	*ray_free(t_ray	*ray);

/*->->->viewport*/
//create
t_viewport *viewport_create(t_img *canva, float horizontal_fov, float distance);
//free
void	*viewport_free(t_viewport *viewport);

/*->->->intersection*/
# define PRECISION 0.001
//intersect
float	ray_intersect(t_ray *ray, t_obj *object);
//quadratic minimum
float	intersection_quadratic_minimum(float a, float b, float c);
//sphere
float	ray_sphere_intersection(t_ray *ray, t_sphere *sphere);
//plane
float	ray_plane_intersection(t_ray *ray, t_plane *plane);
//cylinder
float	ray_cylinder_intersection(t_ray *ray, t_cylinder *cylinder);

/*->->->light*/
//effect
void	light_effect(t_color *color, t_list *scene, t_obj *object, t_vector *intersection);

/*->->->->model*/
//shadow
int	shadow_model(t_list *scene, t_vector *intersection, t_vector *l);
//light intensity
void	light_intensity_model(t_vector *intensity, t_obj *object, t_list *scene, t_vector *intersection);
//ambient lightning
void	ambient_lightning_model(t_vector *intensity, t_ambient_lightning *ambient_lightning);
//light
void	light_point_model(t_vector *intensity, t_light *light, float specular, void *arg[4]);

/*->->->normal*/
//init
void	object_normal_init(t_vector *normal, t_obj *object, t_vector *intersection);
//sphere
void	sphere_normal(t_vector *normal, t_sphere *sphere, t_vector *intersection);
//plane
void	plane_normal(t_vector *normal, t_plane *plane);
//cylinder
void	cylinder_normal(t_vector *normal, t_cylinder *cylinder, t_vector *intersection);

# define CAMERA_VIEWPORT_DISTANCE 1
//method
void	raytracing_method(t_img *canva, t_list *scene, t_viewport *viewport, t_ray *ray);
//render
void	raytracing_render(t_img *canva, t_list *scene);

#endif
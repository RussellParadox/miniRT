/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:15:44 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/30 17:00:16 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	map_color_init(t_map *map, t_img img)
{
	unsigned int	rgb;
	int	            x;
	int	            y;

	x = 0;
	while (x < map->width)
	{
		y = 0;
		while (y < map->height)
		{
			rgb = *(unsigned int *)(img.addr + y * img.line_length + x * (img.bits_per_pixel / 8));
			map->color[x][y] = (t_color){rgb >> 16 & 0xFF, rgb >> 8 & 0xFF, rgb & 0xFF, 0};
			y++;
		}
		x++;
	}
}

void	map_color_allocate(t_map *map)
{
	int	i;

	map->color = malloc(sizeof(t_color *) * (map->width + 1));
	if (map->color == NULL)
		return ;
	i = 0;
	while (i < map->width)
	{
		map->color[i] = malloc(sizeof(t_color) * map->height);
		if (map->color[i] == NULL)
		{
			array_free(map->color, 2);
			return ;
		}
		i++;
	}
	map->color[i] = NULL;
}

void	map_init(t_map *map, char *file_path)
{
	void	        *instance;
	t_img        	img;

	instance = mlx_init();
	if (instance == NULL)
		return ;
	img.instance = mlx_xpm_file_to_image(instance, file_path, &map->width, &map->height);
	//printf("width: %d, height: %d\n", map->width, map->height);
	if (img.instance != NULL)
	{
		map_color_allocate(map);
		img.addr = mlx_get_data_addr(img.instance, &img.bits_per_pixel, &img.line_length, &img.endian);
		if (map->color != NULL)
			map_color_init(map, img);
		mlx_destroy_image(instance, img.instance);
	}
	mlx_destroy_display(instance);
	free(instance);
}

t_map	*map_create(char *file_path)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->width = 0;
	map->height = 0;
	map->color = NULL;
	map_init(map, file_path);
	if (errno == ENOMEM || map->color == NULL)
		return (map_free(map));
	return (map);
}
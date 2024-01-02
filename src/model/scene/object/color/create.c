/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:20:25 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/02 15:38:51 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	*color_create(char *red, char *green, char *blue)
{
	t_color	*color;

	color = malloc(sizeof(t_color));
	if (color == NULL)
		return (NULL);
	color->red = ft_atoi(red);
	color->green = ft_atoi(green);
	color->blue = ft_atoi(blue);
	return (color);
}
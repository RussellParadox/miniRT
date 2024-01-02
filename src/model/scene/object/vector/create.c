/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:00:46 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/02 17:02:12 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	*vector_create(char *x, char *y, char *z)
{
	t_vector	*vector;

	vector = malloc(sizeof(t_vector));
	if (vector == NULL)
		return (NULL);
	vector->x = ascii_to_float(x);
	vector->y = ascii_to_float(y);
	vector->z = ascii_to_float(z);
	return (vector);
}
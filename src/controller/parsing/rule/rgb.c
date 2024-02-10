/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:39:04 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/10 18:45:24 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	rgb_rule(char *rgb)
{
	char	**split;
	int		n;
	int		result;
	int		i;

	result = 0;
	split = ft_split(rgb, ',');
	if (split == NULL)
		return (1);
	if (split_len(split) != 3)
		result = 1;
	i = 0;
	while (!result && i < 3)
	{
		if (int_rule(split[i]))
			result = 1;
		n = ft_atoi(split[i]);
		if (n < 0 || n > 255)
			result = 1;
		i++;
	}
	array_free(split, 2);
	return (result);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:41:44 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/10 18:25:15 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	vector_rule(char *v)
{
	char	**split;
	int		result;
	int		i;

	result = 0;
	split = ft_split(v, ',');
	if (split == NULL)
		return (1);
	if (split_len(split) != 3)
		result = 1;
	i = 0;
	while (!result && i < 3)
	{
		if (float_rule(split[i]))
			result = 1;
		i++;
	}
	array_free(split, 2);
	return (result);
}
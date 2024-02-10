/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_normalized.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:42:20 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/10 18:25:44 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	vector_normalized_rule(char *vn)
{
	char	**split;
	float	n;
	int		result;
	int		i;

	result = 0;
	split = ft_split(vn, ',');
	if (split == NULL)
		return (1);
	if (split_len(split) != 3)
		result = 1;
	i = 0;
	while (!result && i < 3)
	{
		if (float_rule(split[i]))
			result = 1;
		n = ascii_to_float(split[i]);
		if (n < -1 || n > 1)
			result = 1;
		i++;
	}
	array_free(split, 2);
	return (result);
}
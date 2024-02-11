/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:40:21 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 08:49:37 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	float_rule(char *f)
{
	char	**split;
	int		len;
	int		result;

	result = 0;
	split = ft_split(f, '.');
	if (split == NULL)
		return (1);
	len = split_len(split);
	if (len < 0 || len > 2)
		result = 1;
	if (!result && int_rule(split[0]))
		result = 1;
	if (!result && split[1] != NULL)
	{
		if (!ft_isdigit(split[1][0]))
			result = 1;
		if (int_rule(split[1]))
			result = 1;
	}
	array_free(split, 2);
	return (result);
}

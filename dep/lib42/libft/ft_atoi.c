/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:41:48 by gdornic           #+#    #+#             */
/*   Updated: 2023/02/08 17:02:05 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	char	*nptr_cpy;
	int		res;
	int		sign;

	nptr_cpy = (char *)nptr;
	res = 0;
	sign = 1;
	while ((*nptr_cpy >= '\t' && *nptr_cpy <= '\r') || (*nptr_cpy == ' '))
		nptr_cpy++;
	if (*nptr_cpy == '+' || *nptr_cpy == '-')
	{
		if (*nptr_cpy == '-')
			sign = -1;
		nptr_cpy++;
	}
	while (ft_isdigit(*nptr_cpy))
	{
		res = res * 10 + (*nptr_cpy - '0');
		nptr_cpy++;
	}
	return (sign * res);
}

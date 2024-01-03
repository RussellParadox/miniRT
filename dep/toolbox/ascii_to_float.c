/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii_to_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 09:07:17 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/03 16:22:08 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "toolbox.h"
#include <stdio.h>

static int	ft_isdigit(int c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

static int	ft_atoi(const char *nptr)
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

static int	ft_atoi_len(char *str)
{
	int	len;

	len = 0;
	while ((str[len] >= '\t' && str[len] <= '\r') || (str[len] == ' '))
		len++;
	if (str[len] == '+' || str[len] == '-')
		len++;
	while (ft_isdigit(str[len]))
		len++;
	return (len);
}

static int	integer_len(int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

float	ascii_to_float(char *str)
{
	float	integer_part;
	float	fractional_part;
	int		len;

	integer_part = ft_atoi(str);
	len = ft_atoi_len(str);
	fractional_part = 0;
	if (str[len] == '.' && ft_isdigit(str[len + 1]))
		fractional_part = ft_atoi(str + len + 1);
	fractional_part *= powf(10, -integer_len(fractional_part));
	if (integer_part >= 0)
		return (integer_part + fractional_part);
	else
		return (integer_part - fractional_part);
}
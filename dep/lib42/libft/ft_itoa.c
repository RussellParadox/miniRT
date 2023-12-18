/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:48:04 by gdornic           #+#    #+#             */
/*   Updated: 2023/02/15 22:41:14 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbrsize(int n)
{
	size_t	size;

	size = 0;
	if (n == 0)
		size++;
	if (n < 0)
		size++;
	while (n != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

static int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

char	*ft_itoa(int n)
{
	char	*ntostr;
	size_t	nsize;
	size_t	i;

	nsize = ft_nbrsize(n);
	ntostr = (char *)ft_calloc(nsize + 1, sizeof(char));
	if (ntostr != NULL)
	{
		i = nsize - 1;
		if (n == 0)
			ntostr[0] = '0';
		if (n < 0)
			ntostr[0] = '-';
		while (n != 0)
		{
			ntostr[i] = ft_abs(n % 10) + '0';
			n /= 10;
			i--;
		}
	}
	return (ntostr);
}

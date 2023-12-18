/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:48:04 by gdornic           #+#    #+#             */
/*   Updated: 2023/04/01 20:47:27 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static long	ft_nbrsize(long long n, long radix)
{
	long	size;

	size = 0;
	if (n == 0)
		size++;
	if (n < 0)
		size++;
	while (n != 0)
	{
		size++;
		n /= radix;
	}
	return (size);
}

static int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

char	*ft_itoa_base(long long n, char *b)
{
	char	*ntostr;
	long	radix;
	long	nsize;
	long	i;

	radix = ft_strlen(b);
	nsize = ft_nbrsize(n, radix);
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
			ntostr[i] = b[ft_abs(n % radix)];
			n /= radix;
			i--;
		}
	}
	return (ntostr);
}

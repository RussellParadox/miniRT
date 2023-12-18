/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:05:15 by gdornic           #+#    #+#             */
/*   Updated: 2023/02/05 14:06:29 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_revmemcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*pon_dest;
	unsigned char	*pon_src;
	size_t			i;

	pon_dest = (unsigned char *)dest;
	pon_src = (unsigned char *)src;
	i = n;
	while (i > 0)
	{
		pon_dest[i - 1] = pon_src[i - 1];
		i--;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest < src)
		ft_memcpy(dest, src, n);
	else if (dest > src)
		ft_revmemcpy(dest, src, n);
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:45:19 by gdornic           #+#    #+#             */
/*   Updated: 2023/02/14 22:02:08 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*pon_dest;
	unsigned char	*pon_src;
	size_t			i;

	if (dest == NULL && src == NULL)
		return (NULL);
	pon_dest = (unsigned char *)dest;
	pon_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		pon_dest[i] = pon_src[i];
		i++;
	}
	return (dest);
}

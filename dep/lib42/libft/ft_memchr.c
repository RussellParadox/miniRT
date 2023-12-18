/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:59:39 by gdornic           #+#    #+#             */
/*   Updated: 2023/02/07 20:07:40 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*scast;
	unsigned char	ctochr;
	size_t			i;

	scast = (unsigned char *)s;
	ctochr = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*scast == ctochr)
			return (scast);
		scast++;
		i++;
	}
	return (NULL);
}

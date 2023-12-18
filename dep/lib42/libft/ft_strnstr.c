/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:20:16 by gdornic           #+#    #+#             */
/*   Updated: 2023/02/14 22:19:11 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strllen(const char *dst, size_t size)
{
	size_t	len;

	len = 0;
	while (dst[len] && len < size)
		len++;
	return (len);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*big_cpy;
	size_t	little_len;
	size_t	search_zone;
	size_t	i;

	if (big == NULL && len == 0)
		return (0);
	big_cpy = (char *)big;
	little_len = ft_strlen(little);
	if (!little_len)
		return (big_cpy);
	search_zone = ft_strllen(big_cpy, len);
	i = 0;
	while (i + little_len <= search_zone)
	{
		if (!ft_memcmp((const char *)big_cpy, little, little_len))
			return (big_cpy);
		big_cpy++;
		i++;
	}
	return (NULL);
}

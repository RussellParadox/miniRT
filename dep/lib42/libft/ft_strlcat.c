/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:43:00 by gdornic           #+#    #+#             */
/*   Updated: 2023/02/14 22:17:29 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strllen(char *dst, size_t size)
{
	size_t	len;

	len = 0;
	while (dst[len] && len < size)
		len++;
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	free_size;

	if (dst == NULL && size == 0)
		return (0);
	src_len = ft_strlen(src);
	dst_len = ft_strllen(dst, size);
	if (dst_len != size)
	{
		free_size = size - dst_len;
		if (src_len >= free_size)
		{
			ft_memcpy(dst + dst_len, src, free_size - 1);
			dst[dst_len + free_size - 1] = '\0';
		}
		else
		{
			ft_memcpy(dst + dst_len, src, src_len);
			dst[dst_len + src_len] = '\0';
		}
	}
	return (src_len + dst_len);
}

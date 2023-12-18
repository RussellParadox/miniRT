/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:02:14 by gdornic           #+#    #+#             */
/*   Updated: 2023/02/14 22:40:36 by gdornic          ###   ########.fr       */
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	sub_len;
	size_t	slen;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (start < slen)
		sub_len = ft_strllen(s + start, len);
	else
		sub_len = 0;
	sub_str = ft_calloc(sub_len + 1, sizeof(char));
	if (sub_str == NULL)
		return (NULL);
	ft_memcpy(sub_str, s + start, sub_len);
	sub_str[sub_len] = '\0';
	return (sub_str);
}

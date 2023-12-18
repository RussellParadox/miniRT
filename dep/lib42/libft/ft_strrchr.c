/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:10:40 by gdornic           #+#    #+#             */
/*   Updated: 2023/02/07 16:38:04 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occ;
	char	ctochr;

	last_occ = ft_strchr((char *)s, '\0');
	ctochr = (char)c;
	while (last_occ != (char *)s)
	{
		if (*last_occ == ctochr)
			return (last_occ);
		last_occ--;
	}
	if (*last_occ == ctochr)
		return (last_occ);
	return (NULL);
}

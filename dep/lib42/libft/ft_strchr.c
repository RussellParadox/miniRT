/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:49:02 by gdornic           #+#    #+#             */
/*   Updated: 2023/02/07 16:39:26 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*first_occ;
	char	ctochr;

	ctochr = (char)c;
	first_occ = (char *)s;
	while (*first_occ)
	{
		if (*first_occ == ctochr)
			return (first_occ);
		first_occ++;
	}
	if (!ctochr)
		return (first_occ);
	return (NULL);
}

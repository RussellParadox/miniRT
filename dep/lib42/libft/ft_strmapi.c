/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:34:23 by gdornic           #+#    #+#             */
/*   Updated: 2023/02/16 14:55:37 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*scpy;
	size_t	slen;
	size_t	i;

	if (s == NULL || f == (void *)0)
		return (NULL);
	slen = ft_strlen(s);
	scpy = ft_substr(s, 0, slen);
	i = 0;
	while (i < slen && scpy != NULL)
	{
		scpy[i] = (*f)(i, scpy[i]);
		i++;
	}
	return (scpy);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:29:17 by gdornic           #+#    #+#             */
/*   Updated: 2023/02/14 23:27:21 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordqt(char const *s, char c)
{
	size_t	word_qt;
	char	*pon_s;

	word_qt = 0;
	pon_s = (char *)s;
	while (*pon_s)
	{
		while (*pon_s == c)
			pon_s++;
		if (*pon_s != c && (*pon_s || !c))
		{
			word_qt++;
			while (*pon_s != c && *pon_s)
				pon_s++;
		}
	}
	return (word_qt);
}

static size_t	*ft_wordsize(size_t word_qt, char const *s, char c)
{
	size_t	*word_size;
	size_t	size;
	char	*pon_s;

	pon_s = (char *)s;
	word_size = ft_calloc(word_qt, sizeof(size_t));
	if (word_size == NULL)
		return (NULL);
	while (*pon_s)
	{
		while (*pon_s == c)
			pon_s++;
		if (*pon_s != c && (*pon_s || !c))
		{
			size = 0;
			while (*pon_s != c && *pon_s)
			{
				size++;
				pon_s++;
			}
			*word_size = size + 1;
			word_size++;
		}
	}
	return (word_size - word_qt);
}

static char	**ft_splitstr(size_t *word_size, size_t word_qt, \
		char const *s, char c)
{
	char	**split_str;
	size_t	i;
	size_t	j;

	split_str = (char **)ft_calloc(word_qt + 1, sizeof(char *));
	i = 0;
	while (*s && split_str != NULL)
	{
		while (*s == c)
			s++;
		if (*s != c && (*s || !c))
		{
			split_str[i] = (char *)ft_calloc(word_size[i], sizeof(char));
			j = 0;
			while (*s != c && *s)
			{
				split_str[i][j] = *s;
				j++;
				s++;
			}
			i++;
		}
	}
	split_str[i] = NULL;
	return (split_str);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_qt;
	size_t	*word_size;
	char	**split_str;

	if (s == NULL)
		return (NULL);
	word_qt = ft_wordqt(s, c);
	word_size = ft_wordsize(word_qt, s, c);
	if (word_size == NULL)
		return (NULL);
	split_str = ft_splitstr(word_size, word_qt, s, c);
	if (split_str == NULL)
		return (NULL);
	free(word_size);
	return (split_str);
}

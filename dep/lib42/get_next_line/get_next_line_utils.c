/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:41:21 by gdornic           #+#    #+#             */
/*   Updated: 2023/04/02 04:39:25 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_gnl(const char *s, int c)
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

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*new_str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	new_size;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = 0;
	s2_len = 0;
	while (s1[s1_len])
		s1_len++;
	while (s2[s2_len] && s2_len < n)
		s2_len++;
	new_size = s1_len + s2_len + 1;
	if (new_size * sizeof(char) / sizeof(char) != new_size \
		|| new_size * sizeof(char) / new_size != sizeof(char))
		return (NULL);
	new_str = malloc(new_size * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	ft_memmove_gnl(new_str, s1, s1_len);
	ft_memmove_gnl(new_str + s1_len, s2, s2_len);
	new_str[new_size - 1] = '\0';
	return (new_str);
}

void	*ft_memmove_gnl(void *dest, const void *src, size_t n)
{
	unsigned char	*pon_dest;
	unsigned char	*pon_src;
	size_t			i;

	pon_dest = (unsigned char *)dest;
	pon_src = (unsigned char *)src;
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			pon_dest[i] = pon_src[i];
			i++;
		}
	}
	else if (dest > src)
	{
		i = n;
		while (i > 0)
		{
			pon_dest[i - 1] = pon_src[i - 1];
			i--;
		}
	}
	return (dest);
}

void	ft_stackmove(char *stack)
{
	size_t	i;
	size_t	len;

	if (stack == NULL)
		return ;
	len = 0;
	while (stack[len] && stack[len] != '\n')
		len++;
	len++;
	ft_memset_gnl(stack, '\0', len);
	i = 0;
	if (len <= BUFFER_SIZE)
	{
		while (stack[len + i])
		{
			stack[i] = stack[len + i];
			i++;
		}
	}
	ft_memset_gnl(stack + i, '\0', len);
}

/*void	ft_stackmove(char *stack, char *first_occ)
{
	size_t	move_that;

	move_that = BUFFER_SIZE - (first_occ - stack);
	ft_memmove_gnl(stack, first_occ + 1, move_that);
	ft_memset_gnl(stack + move_that, '\0', BUFFER_SIZE - move_that);
}*/

void	*ft_memset_gnl(void *s, int c, size_t n)
{
	unsigned char	*pon_s;
	size_t			i;

	pon_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		pon_s[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

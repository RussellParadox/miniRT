/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:41:44 by gdornic           #+#    #+#             */
/*   Updated: 2023/04/01 20:52:08 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

size_t	ft_lower_bound(int bound, int n)
{
	if (n < bound)
		return (bound);
	return (n);
}

char	*prefix_add(char *prefix, char *str, char id)
{
	if (id == 'p' && str[0] == '-')
		str = ft_strjoin(prefix, str + 1);
	else if (!(id == 'p' && str[0] == '0'))
		str = ft_strjoin(prefix, str);
	else
		str = ft_strdup("(nil)");
	return (str);
}

//manage flags
//return 1 if a non-allowed character is detected
//
//flags order
//[0]: '-'
//[1]: '0'
//[2]: '+'
//[3]: ' '
//[4]: '#'
void	flags_manager(char *flags, char c)
{
	if (c == '-')
		flags[0] = 1;
	else if (c == '0')
		flags[1] = 1;
	else if (c == '+')
		flags[2] = 1;
	else if (c == ' ')
		flags[3] = 1;
	else if (c == '#')
		flags[4] = 1;
}

//get data in field_width and return the number of characters read
int	ft_atoi_field(const char *s, int *field_width)
{
	int	i;

	i = 0;
	while (s[i] && ft_isdigit(s[i]))
	{
		*field_width = *field_width * 10 + s[i] - '0';
		i++;
	}
	return (i);
}

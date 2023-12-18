/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:45:11 by gdornic           #+#    #+#             */
/*   Updated: 2023/04/01 20:52:28 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

//manage the intergers precision
char	*precision_manager(char *str_arg, int *field_width, char id)
{
	char	*res;
	char	*zero_str;
	size_t	arg_len;
	size_t	zero_len;

	arg_len = ft_strlen(str_arg);
	if (str_arg[0] == '-')
		arg_len--;
	if (ft_strchr("diuxX", id) && field_width[2] > (int)arg_len)
	{
		zero_len = ft_lower_bound(0, field_width[2] - arg_len);
		zero_str = (char *)ft_calloc(zero_len + 1, sizeof(char));
		if (zero_str == NULL)
			return (NULL);
		ft_memset(zero_str, '0', zero_len);
		if (str_arg[0] == '-')
			ft_chrswap(&zero_str[0], &str_arg[0]);
		res = prefix_add(zero_str, str_arg, id);
		free(zero_str);
		return (res);
	}
	else if (field_width[1] && field_width[2] == 0 && str_arg[0] == '0')
		return (ft_strdup(""));
	return (ft_strdup(str_arg));
}

//deal with the justification, return the concatenation of str_arg(max len is
//arg_len) and void_str in the good order
//return NULL if an error occurs
char	*justification_dealer(char *str_arg, char *void_str, \
	size_t arg_len, char left_justify)
{
	char	*str;
	char	*tmp;

	str = ft_substr(str_arg, 0, arg_len);
	free(str_arg);
	if (str == NULL)
		return (NULL);
	tmp = str;
	if (left_justify && arg_len == 1)
		str = inclusive_strjoin(str, void_str);
	else if (left_justify)
		str = ft_strjoin(str, void_str);
	else
		str = ft_strjoin(void_str, str);
	free(void_str);
	free(tmp);
	return (str);
}

//manage the potential void from the minimum field width of the format,
//return it into a string
//return NULL if an error occurs
char	*void_manager(int *field_width, char *flags, size_t arg_len, char id)
{
	char	*void_str;
	size_t	void_len;

	void_len = ft_lower_bound(0, field_width[0] - arg_len);
	void_str = ft_balloc(void_len + 1, sizeof(char));
	if (void_str == NULL)
		return (NULL);
	if (id != 's' && id != 'c' && flags[1] && !((flags[0] \
	|| field_width[1]) && ft_strchr("pdiuxX", id)))
		ft_memset(void_str, '0', void_len);
	return (void_str);
}

//manage argument's flags, return the managed argument
char	*argflags_manager(char *str_arg, int *field_width, char *flags, char id)
{
	if (str_arg == NULL && (field_width[2] > 5 || !field_width[1]))
		return (ft_strdup("(null)"));
	else if (str_arg == NULL)
		return (ft_strdup(""));
	else if (flags[2] && ft_strchr("di", id) && !ft_strchr("-", str_arg[0]))
		return (prefix_add("+", str_arg, id));
	else if (flags[3] && ft_strchr("di", id) && !ft_strchr("-", str_arg[0]))
		return (prefix_add(" ", str_arg, id));
	else if (id == 'p' || (flags[4] && str_arg[0] != '0' && id == 'x'))
		return (prefix_add("0x", str_arg, id));
	else if (flags[4] && str_arg[0] != '0' && id == 'X')
		return (prefix_add("0X", str_arg, id));
	else
		return (ft_strdup(str_arg));
}

//deal with the flags and the fields width, return a formated string
//return NULL if an error occurs
char	*data_dealer(char *flags, int *field_width, char *str_arg, char id)
{
	char	*void_str;
	char	*tmp;
	size_t	arg_len;

	str_arg = argflags_manager(str_arg, field_width, flags, id);
	if (str_arg == NULL)
		return (NULL);
	tmp = str_arg;
	str_arg = precision_manager(str_arg, field_width, id);
	free(tmp);
	if (str_arg == NULL)
		return (NULL);
	if (id == 'c')
		arg_len = 1;
	else
		arg_len = ft_strlen(str_arg);
	if (id == 's' && ft_strncmp(str_arg, "(null)", sizeof(str_arg)) \
	&& field_width[1])
		arg_len = ft_min(field_width[2], arg_len);
	void_str = void_manager(field_width, flags, arg_len, id);
	if (!flags[0] && flags[1] && void_str[0] == '0' && (id == 'd' || id == 'i') \
	&& str_arg[0] == '-')
		ft_chrswap(&void_str[0], &str_arg[0]);
	return (justification_dealer(str_arg, void_str, arg_len, flags[0]));
}

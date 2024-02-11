/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:32:42 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 10:27:09 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "toolbox.h"

int	split_len(char **split)
{
	int	len;

	len = 0;
	while (split[len] != NULL)
		len++;
	return (len);
}

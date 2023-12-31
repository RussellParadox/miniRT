/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:01:06 by gdornic           #+#    #+#             */
/*   Updated: 2023/04/01 20:52:45 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_chrswap(char *chr1, char *chr2)
{
	char	tmp;

	tmp = *chr1;
	*chr1 = *chr2;
	*chr2 = tmp;
}

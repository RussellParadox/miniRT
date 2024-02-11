/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capsule.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:23:57 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 10:26:57 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "toolbox.h"

void	*capsule(void *data)
{
	static void	*ptr = NULL;

	if (data != NULL)
		ptr = data;
	return (ptr);
}

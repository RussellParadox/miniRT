/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 06:19:46 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/03 09:08:02 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "toolbox.h"

void	array_nodes_free(void *node, size_t size, unsigned int dimension)
{
	if (node == NULL)
		return ;
	while (*(void **)node != NULL)
	{
		if (dimension > 2)
			array_nodes_free(*(void **)node, size, dimension - 1);
		free(*(void **)node);
		node += size;
	}
}

//free each dimension of a dynamic multi-dimensionnal
//array NULL terminated on any other dimension than the first
void	array_free(void *root, unsigned int dimension)
{
	if (root == NULL)
		return ;
	array_nodes_free(root, sizeof(void *), dimension);
	free(root);
}

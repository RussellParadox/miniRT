/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 08:34:09 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/03 14:45:01 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLBOX_H
# define TOOLBOX_H
# include <stdlib.h>
# include <math.h>

//array free
void	array_free(void *root, unsigned int dimension);

//ascii to float
float	ascii_to_float(char *str);

#endif
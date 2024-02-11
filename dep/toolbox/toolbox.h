/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 08:34:09 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 10:26:27 by gdornic          ###   ########.fr       */
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

//str cmp
int		str_cmp(char *s1, char *s2);

//split len
int		split_len(char **split);

//capsule
void	*capsule(void *data);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:39:10 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/23 23:43:00 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strnjoin(char const *s1, char const *s2, size_t n);
void	*ft_memset_gnl(void *s, int c, size_t n);
char	*ft_strchr_gnl(const char *s, int c);
void	ft_stackmove(char *stack);
void	*ft_memmove_gnl(void *dest, const void *src, size_t n);

#endif

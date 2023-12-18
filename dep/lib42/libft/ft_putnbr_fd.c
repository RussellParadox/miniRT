/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:38:18 by gdornic           #+#    #+#             */
/*   Updated: 2023/02/16 19:57:20 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	mod;

	mod = n;
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n < 10 && n >= 0)
		ft_putchar_fd(n + '0', fd);
	else if (n > -10 && n < 0)
		ft_putchar_fd(-n + '0', fd);
	else
	{
		if (n < 0)
		{
			mod = -(n % 10);
			n = -(n / 10);
		}
		else
		{
			mod = n % 10;
			n /= 10;
		}
		ft_putnbr_fd(n, fd);
		ft_putchar_fd(mod + '0', fd);
	}
}

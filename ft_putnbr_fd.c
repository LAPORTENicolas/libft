/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 23:32:55 by nlaporte          #+#    #+#             */
/*   Updated: 2024/11/10 23:32:56 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print(long n, int fd)
{
	if (n <= 0)
		return ;
	ft_print(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	nn;

	nn = n;
	if (n < 0)
	{
		nn *= -1;
		ft_putchar_fd('-', fd);
	}
	else if (nn == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	ft_print(nn, fd);
}

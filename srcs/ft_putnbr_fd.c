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

#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>

static size_t	ft_intlen(int n)
{
	if (n / 10 == 0)
		return (1);
	return (ft_intlen(n / 10) + 1);
}

static unsigned int	ft_strlen(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

static char	*ft_itoa(int n)
{
	char	*r;
	int		sign;
	size_t	size;

	sign = n;
	if (n < 0)
		size = ft_intlen(n) + 2;
	else
		size = ft_intlen(n) + 1;
	r = malloc(sizeof(char) * size);
	if (r == NULL)
		return (NULL);
	r[--size] = '\0';
	while (size > 0)
	{
		if (n < 0)
			r[--size] = (n % 10) * -1 + '0';
		else
			r[--size] = n % 10 + '0';
		n /= 10;
	}
	if (sign < 0)
		r[0] = '-';
	return (r);
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_putstr_fd(ft_itoa(n), fd);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:07:42 by nlaporte          #+#    #+#             */
/*   Updated: 2025/01/23 14:10:07 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
double	ft_atof(char *s)
{
	double	atof;
	double	tmp;
	int		i;
	int		sign;

	i = 10;
	atof = 0;
	if (s == NULL)
		return (0.);
	sign = get_sign(&s);
	if (ft_isdigit(*s))
		atof += *s++ - '0';
	else
		return (0.);
	s++;
	ft_printf("Je suis la \n");
	while (*s && ft_isdigit(*s))
	{
		tmp = *s++ - '0';
		tmp /= i;
		atof += tmp;
		ft_printf("NB= %\n", tmp);
		i *= 10;
	}
	return (atof * sign);
}
*/
int	ft_printfloat_fd(double n, int fd)
{
	int	i;
	int	printable;

	(void)fd;
	i = 0;
	printable = n;
	if (n < 0)
	{
		n *= -1;
	}
	ft_printf("%i.", printable);
	n -= printable;
	while (i < 8)
	{
		n *= 10;
		printable = (int)n%10;
		ft_printf("%i", printable);
		i++;
	}
	return (i + 2);
}

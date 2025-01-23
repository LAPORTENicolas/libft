/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:43:26 by nlaporte          #+#    #+#             */
/*   Updated: 2024/12/12 21:44:00 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_sign(char **s)
{
	char	c;

	if (!s || !*s || !*(*s))
		return (1);
	c = *(*s);
	if (c == '-')
	{
		*(s) += 1;
		return (-1);
	}
	return (1);
}

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
	while (*s && ft_isdigit(*s))
	{
		tmp = *s++ - '0';
		tmp /= i;
		atof += tmp;
		i *= 10;
	}
	return (atof * sign);
}

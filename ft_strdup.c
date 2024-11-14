/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 02:17:38 by nlaporte          #+#    #+#             */
/*   Updated: 2024/08/29 18:35:03 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*val;

	i = 0;
	val = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (val == NULL)
		return (NULL);
	while (src[i])
	{
		val[i] = src[i];
		i++;
	}
	val[i] = '\0';
	return (val);
}
/*
int	main(int ac, char **av)
{
	printf("ft=%s\n", ft_strdup(av[1]));
	printf("og=%s", strdup(av[1]));
	return (0);
}*/

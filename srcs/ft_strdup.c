/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 04:03:15 by nlaporte          #+#    #+#             */
/*   Updated: 2024/11/10 04:03:17 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		length;
	char	*res;

	length = ft_strlen(s);
	res = malloc(sizeof(char) * (length + 1));
	if (res == NULL)
		return (NULL);
	i = -1;
	while (++i < length)
		res[i] = s[i];
	res[i] = '\0';
	return (res);
}

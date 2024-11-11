/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 02:27:07 by nlaporte          #+#    #+#             */
/*   Updated: 2024/11/10 02:27:10 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i] && i < size - 1)
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strnstr(const char *find, const char *to_find, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (find[i] == to_find[0])
			if (ft_strncmp(&find[i], to_find, ft_strlen(to_find)) == 0)
				return ((char *)&find[i]);
		i++;
	}
	return (NULL);
}

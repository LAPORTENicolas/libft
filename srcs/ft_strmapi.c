/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:48:58 by nlaporte          #+#    #+#             */
/*   Updated: 2024/11/10 22:49:16 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*r;
	size_t			size;
	unsigned int	i;

	if (s == NULL)
		return (malloc(sizeof(char)));
	if (f == NULL)
		return ((char *)s);
	size = ft_strlen(s);
	i = 0;
	r = malloc(sizeof(char) * (size + 1));
	if (r == NULL)
		return (NULL);
	while (s[i])
	{
		*r++ = f(i, s[i]);
		i++;
	}
	return (r - size);
}
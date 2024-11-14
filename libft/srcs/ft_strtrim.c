/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:06:32 by nlaporte          #+#    #+#             */
/*   Updated: 2024/11/10 18:06:33 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

static int	is_inside(const char c, const char *set)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	size_t	length;
	char	*res;

	length = ft_strlen(s);
	res = malloc(sizeof(char) * (length + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < length && i < n)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strtrim(const char *s, const char *set)
{
	size_t	s_s;
	size_t	i;

	i = 0;
	if (s == NULL || set == NULL)
		return (NULL);
	while (s[i] && is_inside(s[i], set) == 1)
		i++;
	s_s = ft_strlen(&s[i]);
	while (is_inside(s[s_s + i - 1], set) == 1)
		s_s--;
	return (ft_strndup(&s[i], s_s));
}

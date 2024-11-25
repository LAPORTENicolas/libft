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
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*res;

	res = malloc(sizeof(char) * (n + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return ((char *)res);
}

char	*ft_strtrim(const char *s, const char *set)
{
	size_t	s_s;
	size_t	i;

	i = 0;
	if (s == NULL || set == NULL)
		return (ft_strndup("", 0));
	while (s[i] && is_inside(s[i], set) == 1)
		i++;
	if (i == ft_strlen(s))
		return (ft_strndup("", 0));
	s_s = ft_strlen(&s[i]);
	while (is_inside(s[s_s + i - 1], set) == 1)
		s_s--;
	return (ft_strndup(&s[i], s_s));
}
/*
MKO 24: mcheck(s, strlen("tripouille") + 1); free(s); showLeaks();
MKO 28: mcheck(s, strlen("tripouille") + 1); free(s); showLeaks();
MKO 48: mcheck(s, 2); free(s); showLeaks();
*/
/*
#include <stdio.h>
int	main(void)
{
	printf("test strtrim\n");
	char *s;

	s = ft_strtrim("   xxx   xxx", " x");
	printf("res %li\n", ft_strlen(s));
	printf("res %li\n", ft_strlen("tripouille"));
	free(s);
	return (0);
}*/

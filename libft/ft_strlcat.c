/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:58:13 by nlaporte          #+#    #+#             */
/*   Updated: 2024/11/14 20:58:21 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_l;
	size_t	src_l;

	i = 0;
	dest_l = ft_strlen(dest);
	src_l = ft_strlen((char *)src);
	if (size <= dest_l)
		return (size + src_l);
	if (size > 0 && dest_l < size)
	{
		while (src[i] != '\0' && i < size - dest_l - 1)
		{
			dest[dest_l + i] = src[i];
			i++;
		}
		dest[dest_l + i] = '\0';
		return (src_l + dest_l);
	}
	return (size);
}
/*
int main(int ac, char **av)
{
	char src[] = "Test strlcat";
	char src2[] = "Test strlcat";
	char dest[100] = "lol";
	char dest2[100] = "lol";
	int size = atoi(av[2]);

	printf("-FT size = %u\n", ft_strlcat(dest, av[1], size));
	printf("dest = %s\n\n", dest);
	printf("-OG size = %u\n", strlcat(dest2, av[1], size));
	printf("dest = %s\n", dest2);
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 23:47:43 by nlaporte          #+#    #+#             */
/*   Updated: 2024/11/09 23:47:44 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	int		last;

	i = 0;
	last = -1;
	while (s[i])
		if (s[i++] == c)
			last = i - 1;
	if (last != -1)
		return ((char *)(s + last));
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 23:49:31 by nlaporte          #+#    #+#             */
/*   Updated: 2024/11/10 23:49:32 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>

#include "includes/libft.h"

#include <assert.h>

void	t(void *c)
{
	printf("t = %i\n", *(int *)c);
}

void	*m(void *c)
{
	return (c);
}

int	main(int ac, char **av)
{
	int		a;
	int		b;
	int		c;
	t_list	*lst;
	t_list	*lst2;

	a = 5;
	b = 6;
	c = 7;
	(void)ac;
	(void)av;
	ft_split("", ' ');
	lst = ft_lstnew((void *)&a);
	ft_lstadd_back(&lst, ft_lstnew((void *)&b));
	ft_lstadd_back(&lst, ft_lstnew((void *)&c));
	printf("size = %i\n", ft_lstsize(lst));
	lst2 = ft_lstmap(lst, m, t);
	(void)lst2;
	ft_lstiter(lst2, t);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 00:20:12 by nlaporte          #+#    #+#             */
/*   Updated: 2024/11/12 16:49:13 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_cpy(t_list *lst, t_list *new, void *(*f)(void *))
{
	if (lst == NULL)
		return ;
	ft_lstadd_back(&new, ft_lstnew(f(lst->content)));
	ft_cpy(lst->next, new, f);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	ft_cpy(lst->next, new, f);
	return (new);
}

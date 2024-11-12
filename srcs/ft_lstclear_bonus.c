/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 23:06:20 by nlaporte          #+#    #+#             */
/*   Updated: 2024/11/11 23:06:23 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *));

void	ft_clear(t_list *lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	ft_clear(lst->next, del);
	ft_lstdelone(lst, del);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	ft_clear(*lst, del);
	*lst = NULL;
}

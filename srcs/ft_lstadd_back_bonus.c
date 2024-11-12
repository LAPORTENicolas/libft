/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:00:58 by nlaporte          #+#    #+#             */
/*   Updated: 2024/11/11 01:00:59 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst == NULL || *lst == NULL || new == NULL)
		return ;
	else if ((*lst)->next != NULL)
		return (ft_lstadd_back(&(*lst)->next, new));
	(*lst)->next = new;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:42:31 by mayyildi          #+#    #+#             */
/*   Updated: 2022/10/14 12:44:09 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_back(t_list **stack, t_list *node)
{
	t_list	*ptr;

	if (*stack)
	{
		ptr = ft_lstlast(*stack);
		ptr->next = node;
		node->next = NULL;
	}
	else
	{
		*stack = node;
		(*stack)->next = NULL;
	}
}

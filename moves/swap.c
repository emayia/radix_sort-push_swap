/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:34:32 by mayyildi          #+#    #+#             */
/*   Updated: 2022/10/14 15:55:37 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*	This function swaps top 2 elements of stack:					*/
/*	• Step 0:	Create head and below pointers						*/
/*	• Step 1:	Create tmp content and index variables (int)		*/
/*	• Step 2:	If sizeof stack is less than 2, return (-1)			*/
/*	• Step 3:	Assign head of stack to head						*/
/*	• Step 4:	Assign next node to below							*/
/*	• Step 5:	If head and below are empty, call ft_error()		*/
/*	• Step 6:	Copy content of head to tmp_content					*/
/*	• Step 7:	Copy index of head to tmp_index						*/
/*	• Step 8:	Replace content of head with content of below		*/
/*	• Step 9:	Replace index of head with index of below			*/
/*	• Step 10:	Replace content of below with tmp_content (head_c)	*/
/*	• Step 11:	Replace index of below with tmp_index (head_i)		*/
/*	• Step 12:	Return (0) [SUCCESS]								*/
int	swap(t_list **stack)
{
	t_list	*head;
	t_list	*below;
	int		tmp_content;
	int		tmp_index;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	below = head->next;
	if (!head && !below)
		ft_error();
	tmp_content = head->content;
	tmp_index = head->index;
	head->content = below->content;
	head->index = below->index;
	below->content = tmp_content;
	below->index = tmp_index;
	return (0);
}

/*	This function swaps top 2 nodes of stack_a:						*/
/*	• Step 0:	If sizeof stack_a is less than 2, stop				*/
/*	• Step 2:	Print name of movement to the stdout				*/
/*	• Step 1:	Otherwise, swap top 2 elements of stack_a			*/
void	sa(t_list **stack_a)
{
	if (swap(stack_a) == -1)
		return ;
	write(1, "sa\n", 3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:23:50 by mayyildi          #+#    #+#             */
/*   Updated: 2022/10/14 15:53:24 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*	This function takes top node of stack and moves it to bottom:	*/
/*	• Step 0:	Create head and tail pointers						*/
/*	• Step 1:	If sizeof stack is < 2, return (-1)					*/
/*	• Step 2:	Assign top of stack to head							*/
/*	• Step 3:	Assign bottom of stack to tail w/ ft_lstlast()		*/
/*	• Step 4:	New head of stack is head->next						*/
/*	• Step 5:	Old head now points to NULL (so it becomes new tail)*/
/*	• Step 6:	Tail points to head (so it becomes new head)		*/
/*	• Step 7:	Return (0) [SUCCESS]								*/
int	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

/*	This function takes top of stack_a and moves it to bottom:		*/
/*	• Step 0:	If sizeof stack_a is less than 2, stop				*/
/*	• Step 1:	Otherwise, move top of stack_a to bottom			*/
/*	• Step 2:	Print name of movement to the stdout				*/
void	ra(t_list **stack_a)
{
	if (rotate(stack_a) == -1)
		return ;
	write(1, "ra\n", 3);
}

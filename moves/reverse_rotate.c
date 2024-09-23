/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:34:02 by mayyildi          #+#    #+#             */
/*   Updated: 2022/10/14 15:51:34 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*	This function takes the bottom node of stack and puts it to top:*/
/*	• Step 0:	Create head and tail pointers						*/
/*	• Step 1:	If sizeof stack is less than 2, return (-1)			*/
/*	• Step 2:	Make head point to top of stack						*/
/*	• Step 3:	Make tail point to bottom of stack w/ ft_lstlast()	*/
/*	• Step 4:	While head != NULL:									*/
/*				• Step 4.1:	If the node two steps away is tail:		*/
/*					• Step 4.1.1:	head->next = NULL (new tail)	*/
/*					• Step 4.1.2:	Break from the loop				*/
/*				• Step 4.2:	Move to the next node					*/
/*	• Step 5:	Return (0) [SUCCESS]								*/
int	reverse_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (0);
}

/*	This function takes bottom node of stack_a and moves it to top:	*/
/*	• Step 0:	If sizeof stack_a is less than 2, stop				*/
/*	• Step 1:	Otherwise, move bottom of stack_a to top			*/
/*	• Step 2:	Print name of movement to the stdout				*/
void	rra(t_list **stack_a)
{
	if (reverse_rotate(stack_a) == -1)
		return ;
	write(1, "rra\n", 4);
}

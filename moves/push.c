/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:00:55 by mayyildi          #+#    #+#             */
/*   Updated: 2022/10/14 15:50:56 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*	This is our function used for moves like pa() and pb():			*/
/*	• Step 0:	Create tmp, dst_head and src_head pointers			*/
/*	• Step 1:	If sizeof stack of origin is 0, return (-1)			*/
/*	• Step 2:	Make dst_head point to top of dst_stack				*/
/*	• Step 3:	Make src_head point to top of src_stack				*/
/*	• Step 4:	Make tmp point to src_head							*/
/*	• Step 5:	Move src_head to next node of same stack			*/
/*	• Step 6:	Make that same node new head of src_stack			*/
/*	• Step 7:	If dst_stack is empty:								*/
/*				• Step 7.1:	Give value of tmp to dst_head			*/
/*				• Step 7.2:	Make dst_head point to NULL				*/
/*				• Step 7.3:	Make dst_head new head of dst_stack		*/
/*	• Step 8:	Else (if dst_stack contains other nodes):			*/
/*				• Step 8.1:	Make tmp point to current dst_head		*/
/*				• Step 8.2:	Make tmp new head of dst_stack			*/
/*	• Step 9:	Return (0) [SUCCESS]								*/
int	push(t_list **dst_stack, t_list **src_stack)
{
	t_list	*tmp;
	t_list	*dst_head;
	t_list	*src_head;

	if (ft_lstsize(*src_stack) == 0)
		return (-1);
	dst_head = *dst_stack;
	src_head = *src_stack;
	tmp = src_head;
	src_head = src_head->next;
	*src_stack = src_head;
	if (!dst_head)
	{
		dst_head = tmp;
		dst_head->next = NULL;
		*dst_stack = dst_head;
	}
	else
	{
		tmp->next = dst_head;
		*dst_stack = tmp;
	}
	return (0);
}

/*	This function moves top node of stack_b to top of stack_a:		*/
/*	• Step 0:	If src stack is empty, stop							*/
/*	• Step 1:	Otherwise, push top of stack_b to top of stack_a	*/
/*	• Step 2:	Print name of movement to the stdout				*/
void	pa(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return ;
	write(1, "pa\n", 3);
}

/*	This function moves top node of stack_a to top of stack_b:		*/
/*	• Step 0:	If src stack is empty, stop							*/
/*	• Step 1:	Otherwise, push top of stack_a to top of stack_b	*/
/*	• Step 2:	Print name of movement to the stdout				*/
void	pb(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return ;
	write(1, "pb\n", 3);
}

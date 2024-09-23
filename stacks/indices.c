/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indices.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:32:05 by mayyildi          #+#    #+#             */
/*   Updated: 2022/10/14 16:45:06 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*	This function finds the smallest index of the stack:			*/
/*	• Step 0:	Create head pointer									*/
/*	• Step 1:	Create min variable									*/
/*	• Step 2:	Make head point to top of stack						*/
/*	• Step 3:	Give min index of head								*/
/*	• Step 4:	While head->next isn't NULL:						*/
/*				• Step 4.1:	Move head to next node					*/
/*				• Step 4.2:	If head->index < min && index is valid	*/
/*							• Step 4.2.1: Index of head is new min	*/
/*	• Step 5:	Return (min)										*/
int	find_min_index(t_list **stack, int nb)
{
	t_list	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != nb)
			min = head->index;
	}
	return (min);
}

/*	This function looks for smallest value in nodes of list:		*/
/*	• Step 0:	Create head and min pointers						*/
/*	• Step 1:	Create min_flag variable							*/
/*	• Step 2:	Make head point to beginning of stack				*/
/*	• Step 3:	Set min to NULL										*/
/*	• Step 4:	Set min_flag to 0 (false[ie we didn't set min yet])	*/
/*	• Step 5:	If and while head isn't empty:						*/
/*	|			• Step 5.1:	If head's index isn't set yet (-1) AND	*/
/*	|			|			min_flag is set to false(0) OR			*/
/*	|			|			head's content < min's content:			*/
/*	|			|			• Step 5.1.1:	min = head				*/
/*	|			|			• Step 5.1.2:	Set min_flag to 1 (true)*/
/*	|			• Step 5.2:	Move head to next node					*/
/*	• Step 6:	Return min node										*/
t_list	*next_min_content(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		min_flag;

	head = *stack;
	min = NULL;
	min_flag = 0;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!min_flag
					|| head->content < min->content))
			{
				min = head;
				min_flag = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

/*	This function helps us assign indices to the nodes of a stack,	*/
/*	in ascending order:												*/
/*	• Step 0:	Create head pointer									*/
/*	• Step 1:	Create index variable								*/
/*	• Step 2:	Make head point to node w/ smallest content			*/
/*	• Step 3:	Set index to 0										*/
/*	• Step 4:	While we haven't reached end of stack:				*/
/*				• Step 4.1:	Assign index of 0 to head's index		*/
/*				• Step 4.2:	Increment index							*/
/*				• Step 4.3:	Make next min the head of stack			*/
void	assign_indices(t_list **stack)
{
	t_list	*head;
	int		index;

	head = next_min_content(stack);
	index = 0;
	while (head)
	{
		head->index = index++;
		head = next_min_content(stack);
	}
}

/*	This function helps us find the distance from the smallest		*/
/*	index to the top of the stack:									*/
/*	• Step 0:	Create head pointer									*/
/*	• Step 1:	Create distance variable							*/
/*	• Step 2:	Make head point to top of stack						*/
/*	• Step 3:	Set distance to 0									*/
/*	• Step 4:	While head isn't NULL:								*/
/*				• Step 4.1:	If index of head is min index, break    */
/*				• Step 4.2:	Increment dist by one					*/
/*				• Step 4.3:	Move head to next node of the list		*/
/*	• Step 5:	Return the dist from smallest index to top of stack	*/
int	find_dist(t_list **stack, int min)
{
	t_list	*head;
	int		dist;

	head = *stack;
	dist = 0;
	while (head)
	{
		if (head->index == min)
			break ;
		dist++;
		head = head->next;
	}
	return (dist);
}

/*	This function finds upper bound of >> operation on indices:		*/
/*	• Step 0:	Create head pointer									*/
/*	• Step 1:	Create max_index and max_shift variables			*/
/*	• Step 2:	Make head point to top of given stack				*/
/*	• Step 3:	Give max_index head's index							*/
/*	• Step 4:	While head != NULL:									*/
/*	|			• Step 4.1:	If head's index > max_index:			*/
/*	|			|			• Step 4.1.1:   Max_index = head->index	*/
/*	|			• Step 4.2:	Move head to next node					*/
/*	• Step 5:	While we can right shift max_index max_shift (0)	*/
/*	|			times without it resulting in 0:					*/
/*	|			• Step 5.1:	Increment max_shift						*/
/*	• Step 6:	Found upper bound of >> op, return (max_shift)		*/
int	find_max_shift(t_list **stack)
{
	t_list	*head;
	int		max_index;
	int		max_shift;

	head = *stack;
	max_index = head->index;
	max_shift = 0;
	while (head)
	{
		if (head->index > max_index)
			max_index = head->index;
		head = head->next;
	}
	while ((max_index >> max_shift) != 0)
		max_shift++;
	return (max_shift);
}

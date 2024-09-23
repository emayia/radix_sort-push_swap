/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:02:38 by mayyildi          #+#    #+#             */
/*   Updated: 2022/10/14 16:21:46 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*	We use this function to sort stacks of 3 elements:				*/
/*	• Step 0:	Check if stack_a is sorted or not					*/
/*	• Step 1:	If head's index is smallest index and the next		*/
/*				node's index isn't the next_smallest (which would	*/
/*				mean stack is already sorted...):					*/
/*				• Step 1.1:	ra()[biggest node goes from mid to top]	*/
/*				• Step 1.2:	sa()[next_min goes on top of stack]		*/
/*				• Step 1.3:	rra()[smallest node goes on top]		*/
/*	• Step 2:	Else if head's index is same as next_min:			*/
/*				• Step 2.1:	If next node's index is same as min:	*/
/*							• Step 2.1.1:	sa()					*/
/*				• Step 2.2:	Else, rra()								*/
/*	• Step 3:	Else (head's index is biggest of list):				*/
/*				• Step 3.1:	If next node is smallest, ra()			*/
/*				• Step 3.2:	Else, swap top 2 nodes and do rra()		*/
void	sort_3_moves(t_list **stack_a, t_list *head, int min, int next_min)
{
	if (check_sort(stack_a))
		return ;
	if (head->index == min && head->next->index != next_min)
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
	else if (head->index == next_min)
	{
		if (head->next->index == min)
			sa(stack_a);
		else
			rra(stack_a);
	}
	else
	{
		if (head->next->index == min)
			ra(stack_a);
		else
		{
			sa(stack_a);
			rra(stack_a);
		}
	}
}

/*	We use this function to sort stacks of 3 elements:				*/
/*	• Step 0:	Create head pointer									*/
/*	• Step 1:	Create min and next_min variables					*/
/*	• Step 2:	Make head point to top of stack_a					*/
/*	• Step 3:	Min contains the smallest index of the list			*/
/*	• Step 4:	Next_min contains the next smallest min of the list	*/
/*	• Step 5:	Send all of the above to sort_3_moves()				*/
void	sort_3(t_list **stack_a)
{
	t_list	*head;
	int		min;
	int		next_min;

	head = *stack_a;
	min = find_min_index(stack_a, -1);
	next_min = find_min_index(stack_a, min);
	sort_3_moves(stack_a, head, min, next_min);
}

/*	We use this function to sort stacks of 4 elements:				*/
/*	• Step 0:	Create distance variable							*/
/*	• Step 1:	Check if stack_a is already sorted					*/
/*	• Step 2:	Get distance value w/ find_dist() + find_min_index()*/
/*	--------------------------------------------------------------	*/
/*	• Note: By distance we mean the distance the smallest index		*/
/*			has to cross to reach the top (i.e. moves to reach top)	*/
/*	--------------------------------------------------------------	*/
/*	• Step 3:	If dist is 1, move top element to bottom			*/
/*	• Step 4:	Else if dist is 2, ra() two times					*/
/*	• Step 5:	Else if dist is 3 (so smallest index is at bottom	*/
/*				of stack), rra() so that it moves to top			*/
/*	• Step 6:	If the stack is sorted, stop						*/
/*	• Step 7:	Otherwise, push smallest index to stack_b			*/
/*	• Step 8:	Sort 3 remaining nodes in stack_a w/ sort_3()		*/
/*	• Step 9:	Push smallest index back to top of stack_a			*/
void	sort_4(t_list **stack_a, t_list **stack_b)
{
	int	dist;

	if (check_sort(stack_a))
		return ;
	dist = find_dist(stack_a, find_min_index(stack_a, -1));
	if (dist == 1)
		ra(stack_a);
	else if (dist == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (dist == 3)
		rra(stack_a);
	if (check_sort(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

/*	We use this function to sort stacks of 5 elements:				*/
/*	• Step 0:	Create distance variable							*/
/*	• Step 1:	Get distance value w/ find_dist() + find_min_index()*/
/*	--------------------------------------------------------------  */
/*	• Note: By distance we mean the distance the smallest index		*/
/*			has to cross to reach the top (i.e. moves to reach top)	*/
/*	--------------------------------------------------------------	*/
/*	• Step 2:	If dist is 1, move top element to bottom			*/
/*	• Step 3:	Else if dist is 2, ra() two times					*/
/*	• Step 4:	Else if dist is 3, rra() two times					*/
/*	• Step 5:	Else if dist is 4 (so smallest index is at bottom	*/
/*				of stack), rra() so that it moves to top			*/
/*	• Step 6:	If the stack is sorted, stop						*/
/*	• Step 7:	Otherwise, push smallest index to stack_b			*/
/*	• Step 8:	Sort 4 remaining nodes in stack_a w/ sort_4()		*/
/*	• Step 9:	Push smallest index back to top of stack_a			*/
void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	dist;

	dist = find_dist(stack_a, find_min_index(stack_a, -1));
	if (dist == 1)
		ra(stack_a);
	else if (dist == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (dist == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (dist == 4)
		rra(stack_a);
	if (check_sort(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}

/*	This function helps us sort small amounts of elements (<= 5):	*/
/*	• Step 0:	Create size variable								*/
/*	• Step 1:	If stack_a is sorted, is empty or has 1 nb, stop	*/
/*	• Step 2:	If sizeof stack = 2:............do sa()				*/
/*	• Step 3:	Else if sizeof stack = 3:.......call sort_3()		*/
/*	• Step 4:	Else if sizeof stack = 4:.......call sort_4()		*/
/*	• Step 5:	Else if sizeof stack = 5:.......call sort_5()		*/
void	small_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (check_sort(stack_a) || size <= 1)
		return ;
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}

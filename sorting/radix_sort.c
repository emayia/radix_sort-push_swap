/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:42:20 by mayyildi          #+#    #+#             */
/*   Updated: 2022/10/14 15:58:04 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*	This function helps us sort a stack using bitwise operations:	*/
/*	• Step 0:	Create pointer to top of stack_a					*/
/*	• Step 1:	Create i and j iterators							*/
/*	• Step 2:	Create stack_size and max_shift variables			*/
/*	• Step 3:	Set i to 0											*/
/*	• Step 4:	Make head_a point to top of stack_a					*/
/*	• Step 5:	Put sizeof stack_a to stack_size using ft_lstsize()	*/
/*	• Step 6:	Find upper bound of >> op using find_max_shift()	*/
/*	• Step 7:	While i is less than max_shift:						*/
/*				• Step 7.1:	Set j to 0								*/
/*				• Step 7.2:	While j++ is less than sizeof stack:	*/
/*				|			• 7.2.1: Make head_a point to top of a	*/
/*	- Note: When say 'ends in 1' or 0, it's a ref to index in bits	*/
/*				|			• 7.2.2: If head_a->index>>i ends in 1	*/
/*				|					• 7.2.2.1: ra()					*/
/*				|					i.e. keep it in 1's box			*/
/*				|					• 7.2.2.1: pb()					*/
/*				|					i.e. send it to 0's box			*/
/*				|			• 7.2.3: Repeat 7.2.1 and 7.2.2			*/
/*				• Step 7.3:	pb() till stack_b is empty				*/
/*				• Step 7.4:	Increment i by one						*/
/*				• Step 7.5:	Repeat 7.1 to 7.4						*/
void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	int		i;
	int		j;
	int		stack_size;
	int		max_shift;

	i = 0;
	head_a = *stack_a;
	stack_size = ft_lstsize(head_a);
	max_shift = find_max_shift(stack_a);
	while (i < max_shift)
	{
		j = 0;
		while (j++ < stack_size)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}

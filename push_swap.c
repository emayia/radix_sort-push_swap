/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:09:10 by mayyildi          #+#    #+#             */
/*   Updated: 2022/10/14 17:29:22 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	This is my main function, this is what it does:					*/
/*	• Step 0:	Create stack_a and stack_b							*/
/*	• Step 1:	Set their values to NULL respectively				*/
/*	• Step 2:	Check ac count, if < 2, leave program				*/
/*	• Step 3:	Check the validity of av using check_args()			*/
/*	• Step 4:	If av is valid, call fill_stack() for stack_a		*/
/*	• Step 5:	Check if stack_a is already sorted. If so:			*/
/*	|			• Free stack_a and stack_b							*/
/*	|			• Return (0)										*/
/*	• Step 6:	Else, sort stack_a using sort_stack()				*/
/*	• Step 7:	Once it's done, free stack_a and stack_b			*/
/*	• Step 8:	Exit program with a return value of (0)				*/
int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (-1);
	check_args(ac, av);
	fill_stack(&stack_a, ac, av);
	if (check_sort(&stack_a))
	{
		free_stack(&stack_a);
		free_stack(&stack_b);
		return (0);
	}
	sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

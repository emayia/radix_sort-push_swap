/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:45:26 by mayyildi          #+#    #+#             */
/*   Updated: 2022/10/14 16:47:48 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*	This function allows us to fill our stack:						*/
/*	• Step 0:	Create new node, array of args, and iterator		*/
/*	• Step 1:	Set iterator to 0									*/
/*	• Step 2:	If ac is 2, fill args with split of av[1]			*/
/*	• Step 3:	Else, set args to av + 1 so that we ignore av[0]	*/
/*	• Step 4:	While args[i] != NULL:								*/
/*	|			• Step 4.1:	Fill new node with atoi(av[i])			*/
/*	|			• Step 4.2:	Place new node to back of stack w/		*/
/*	|			|			the help of ft_lstadd_back()			*/
/*	|			• Step 4.3:	Increment iterator						*/
/*	• Step 5:	Assign indices of each node using assign_indices()	*/
/*	• Step 6:	If ac is 2, free args since we don't need it anymore*/
void	fill_stack(t_list **stack, int ac, char **av)
{
	t_list	*new_node;
	char	**args;
	int		i;

	i = 0;
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
		args = av + 1;
	while (args[i])
	{
		new_node = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new_node);
		i++;
	}
	assign_indices(stack);
	if (ac == 2)
		ft_free(args);
}

/*	Here we chose the adequate way of sorting stack based on size:	*/
/*	• Step 0:	If stack has 5 or less elements, call small_sort()	*/
/*	• Step 1:	Else, call radix_sort()								*/
void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
		small_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

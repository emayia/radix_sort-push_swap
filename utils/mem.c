/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:51:16 by mayyildi          #+#    #+#             */
/*   Updated: 2022/10/14 16:53:10 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*	This function frees an array of strings:						*/
/*	• Step 0:	Count the number of arguments in array				*/
/*	• Step 1:	Free arguments from last to first					*/
void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
}

/*	Same as above, but with stacks:									*/
/*	• Step 0:	Create head that points to beginning of stack		*/
/*	• Step 1:	Make so that tmp pointer points to current head		*/
/*	• Step 2:	Move head to the next node							*/
/*	• Step 3:	Free tmp											*/
/*	• Step 4:	Repeat steps 1 to 3 until stack is empty			*/
/*	• Step 5:	Set stack to NULL so that we totally remove any ref	*/
/*				to previous address stack used to point to			*/
void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	*stack = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:23:25 by mayyildi          #+#    #+#             */
/*   Updated: 2022/10/14 16:30:11 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*	This function checks if we have duplicates in our args:			*/
/*	• Step 0:	Increment i so that we move one step further than	*/
/*				our tmp number										*/
/*	• Step 1:	Compare our tmp nb with every arguments				*/
/*	• Step 2:	If dup found, return (1)							*/
/*	• Step 3:	Else return (0)										*/
int	check_dup(int nb, char **av, int i)
{
	i++;
	while (av[i])
	{
		if (ft_atoi(av[i]) == nb)
			return (1);
		i++;
	}
	return (0);
}

/*	This function checks if our argument is a valid number or not:	*/
/*	• Step 0:	Check if first char of arg is minus sign			*/
/*	• Step 1:	If it is a minus sign, increment i by one			*/
/*	• Step 2:	Check if each char isdigit() and increment i		*/
/*	• Step 3:	If char isn't digit, return (0)						*/
/*	• Step 4:	Else return (1)										*/
int	check_nb(char *nb)
{
	int	i;

	i = 0;
	if (nb[0] == '-')
		i++;
	while (nb[i])
	{
		if (!ft_isdigit(nb[i]))
			return (0);
		i++;
	}
	return (1);
}

/*	This function checks the validity of our arguments:				*/
/*	• Step 0:	If we have only 2 arguments, split av[1] and send	*/
/*				the results to args variable						*/
/*	• Step 1:	Else our args is av + 1 (we ignore av[0])			*/
/*	• Step 2:	Store current arg in tmp							*/
/*	• Step 3:	Check if tmp is a nb with check_nb()				*/
/*	• Step 4:	Check if tmp has a duplicate with check_dup()		*/
/*	• Step 5:	Check if tmp goes beyond INT_MIN||MAX range			*/
/*	• Step 6:	Repeat steps 2 to 5 until reach the end of args		*/
/*	• Step 7:	If our ac is equal to 2, free args					*/
void	check_args(int ac, char **av)
{
	int		i;
	long	tmp;
	char	**args;

	i = 0;
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
		args = av + 1;
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!check_nb(args[i]))
			ft_error();
		if (check_dup(tmp, args, i))
			ft_error();
		if (tmp < INT_MIN || tmp > INT_MAX)
			ft_error();
		i++;
	}
	if (ac == 2)
		ft_free(args);
}

/*	This function checks if our stack is sorted or not:				*/
/*	• Step 0:	Create head pointer									*/
/*	• Step 1:	Make head point to beginning of stack				*/
/*	• Step 2:	While head & head->next aren't NULL:				*/
/*				• Step 2.1:	If head is > next node: return (0)		*/
/*	• Step 3:	Return (1) if list is already sorted				*/
int	check_sort(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->content > head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
}

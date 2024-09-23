/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:49:57 by mayyildi          #+#    #+#             */
/*   Updated: 2022/10/14 16:51:03 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*	Simple function that handles errors:							*/
/*	• Step 0:	Display error message on stdout						*/
/*	• Step 1:	Exit program with EXIT_FAILURE option				*/
void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

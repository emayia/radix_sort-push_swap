/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:02:43 by mayyildi          #+#    #+#             */
/*   Updated: 2022/10/14 17:23:39 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

/*	-----	Stack structure	-----	*/
typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}				t_list;

/*	-----	Minilib	-----	*/
long	ft_atoi(const char *str);
int		ft_isdigit(int c);
char	**ft_split(char const *s, char c);
int		ft_lstsize(t_list *head);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *head);
void	ft_lstadd_back(t_list **stack, t_list *new);

/*	-----	Moves	-----	*/
/*	Push	*/
int		push(t_list **dst_stack, t_list **src_stack);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_b, t_list **stack_a);
/*	Swap	*/
int		swap(t_list **stack);
void	sa(t_list **stack_a);
/*	Rotate	*/
int		rotate(t_list **stack);
void	ra(t_list **stack_a);
/*	Reverse rotate	*/
int		reverse_rotate(t_list **stack);
void	rra(t_list **stack_a);

/*	-----	Sorting	-----	*/
void	radix_sort(t_list **stack_a, t_list **stack_b);
void	small_sort(t_list **stack_a, t_list **stack_b);

/*	-----	Stacks	-----	*/
/*	Checks	*/
void	check_args(int ac, char **av);
int		check_dup(int nb, char **av, int i);
int		check_nb(char *nb);
int		check_sort(t_list **stack);
/*	Indices	*/
t_list	*next_min_content(t_list **stack);
int		find_min_index(t_list **stack, int nb);
int		find_dist(t_list **stack, int min);
void	assign_indices(t_list **stack);
int		find_max_shift(t_list **stack);
/*	Op	*/
void	fill_stack(t_list **stack, int ac, char **av);
void	sort_stack(t_list **stack_a, t_list **stack_b);

/*	-----	Utils	-----	*/
/*	Memory	*/
void	ft_free(char **str);
void	free_stack(t_list **stack);
/*	Errors	*/
void	ft_error(void);

#endif

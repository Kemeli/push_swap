/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 00:12:54 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/02/08 01:51:26 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN 2147483648

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_tils
{
	int	*ordered_arr;
	int	*original_arr;
	int	size;
	int	check;
	int	len_a;
}	t_utils;

void	order_array(int *numbers, int index, int pivot);
t_stack	*get_list_num(t_stack *list, t_utils *utils, int size);
void	start_values(t_utils *utils, char **argv, int argc);
void	check_args(int argc, char **argv, t_utils *utils);
void	sort_numbers(t_stack **a, t_stack **b, int n, t_utils *utils);
void	radix(t_stack **a, t_stack	**b, int max_num, t_utils *utils);
void	ra(t_stack **a);
void	pb(t_stack **a, t_stack **b, t_utils *utils);
void	pa(t_stack **a, t_stack **b, t_utils *utils);
void	rra(t_stack **a);
void	sa(t_stack **a);
int		ordered_stack(t_stack *a);
int		list_size(t_stack *lst);
void	free_stuff(t_stack *list, t_utils *utils);

#endif

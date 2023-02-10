/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:59:03 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/02/08 01:52:06 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	bigger_num(t_stack *a)
{
	t_stack	*aux;
	int		bigger;

	bigger = a->index;
	aux = a->next;
	while (aux)
	{
		if (bigger < aux->index)
			bigger = aux->index;
		aux = aux->next;
	}
	return (bigger);
}

void	order_three(t_stack **a)
{
	t_stack	*aux;
	int		counter;

	counter = 0;
	if (!ordered_stack(*a))
	{
		aux = *a;
		while (aux->next && aux->index != bigger_num(*a))
		{
			aux = aux->next;
			counter++;
		}
		if (counter == 0)
			ra(a);
		else if (counter == 1 || counter == 2)
			sa(a);
		order_three(a);
	}
}

void	take_smaller_index(t_stack **a, t_stack **b, t_utils *utils, int small)
{
	t_stack	*aux;
	int		counter;

	counter = 0;
	aux = *a;
	while (aux && aux->index != small)
	{
		aux = aux->next;
		counter++;
	}
	if (!aux || ordered_stack(*a))
		return ;
	if (counter == 0)
		pb(a, b, utils);
	else if (counter == 1)
		sa(a);
	else if (counter == 2)
		ra(a);
	else if (counter == 3 || counter == 4)
		rra(a);
	take_smaller_index(a, b, utils, small);
}

void	*four_or_five(t_stack **a, t_stack **b, t_utils *utils, int smaller)
{
	if (ordered_stack(*a) && !list_size(*b))
		return (a);
	if (utils->len_a > 3)
		take_smaller_index(a, b, utils, smaller);
	if (utils->len_a == 3)
		order_three(a);
	while (ordered_stack(*a) && list_size(*b))
		pa(a, b, utils);
	a = four_or_five(a, b, utils, smaller + 1);
	return (a);
}

void	sort_numbers(t_stack **a, t_stack **b, int n, t_utils *utils)
{
	if (n == 2)
		sa(a);
	else if (n == 3)
		order_three(a);
	else if (n == 4 || n == 5)
		four_or_five(a, b, utils, 0);
	else
		radix(a, b, utils->len_a, utils);
}

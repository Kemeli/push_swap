/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:05:10 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/02/08 00:36:43 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*aux;

	aux = *a;
	while (aux->next != NULL)
		aux = aux->next;
	aux->next = *a;
	*a = (*a)->next;
	aux->next->next = NULL;
	ft_printf("ra\n");
}

void	pa(t_stack **a, t_stack **b, t_utils *utils)
{
	t_stack	*aux;

	aux = *b;
	*b = (*b)->next;
	aux->next = *a;
	*a = aux;
	utils->len_a++;
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b, t_utils *utils)
{
	t_stack	*aux;

	aux = *a;
	*a = (*a)->next;
	aux->next = *b;
	*b = aux;
	utils->len_a--;
	ft_printf("pb\n");
}

void	sa(t_stack **a)
{
	t_stack	*aux;

	aux = *a;
	*a = (*a)->next;
	aux->next = (*a)->next;
	(*a)->next = aux;
	ft_printf("sa\n");
}

void	rra(t_stack **a)
{
	t_stack	*aux;

	aux = *a;
	while (aux->next->next != NULL)
		aux = aux->next;
	if (aux->next->next == NULL)
	{
		aux->next->next = (*a);
		*a = aux->next;
		aux->next = NULL;
	}
	ft_printf("rra\n");
}

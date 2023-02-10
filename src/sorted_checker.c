/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:56:00 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/02/08 00:35:01 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ordered_stack(t_stack *a)
{
	t_stack	*aux;

	aux = a;
	while (aux->next && aux->index < aux->next->index)
		aux = aux->next;
	if (aux->next == NULL)
		return (1);
	else
		return (0);
}

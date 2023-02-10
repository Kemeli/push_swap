/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:23:51 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/02/08 01:51:42 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	radix(t_stack **a, t_stack	**b, int max_num, t_utils *utils)
{
	int	i;
	int	j;
	int	max_bits;

	i = -1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	while (++i < max_bits)
	{
		j = 0;
		while (j < max_num)
		{
			if (a == NULL)
				break ;
			if ((((*a)->index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b, utils);
			j++;
		}
		while (list_size(*b))
			pa(a, b, utils);
	}
}

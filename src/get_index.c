/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:13:02 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/02/08 00:29:07 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_ordered(int *numbers, int index, int size)
{
	while (index < size)
	{
		if (numbers[index] > numbers[index + 1])
			return (0);
		index++;
	}
	return (1);
}

void	order_array(int *numbers, int index, int pivot)
{
	int	mid;
	int	aux;

	mid = index;
	aux = 0;
	if (!is_ordered(numbers, index, pivot))
	{
		while (numbers[index] != numbers[pivot])
		{
			if (numbers[index] < numbers[pivot])
			{
				aux = numbers[index];
				numbers[index] = numbers[mid];
				numbers[mid] = aux;
				mid++;
			}
			index++;
		}
		aux = numbers[pivot];
		numbers[pivot] = numbers[mid];
		numbers[mid] = aux;
		order_array(numbers, 0, mid - 1);
		order_array(numbers, mid + 1, pivot);
	}
}

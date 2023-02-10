/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:00:25 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/02/08 00:37:05 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stuff(t_stack *list, t_utils *utils)
{
	t_stack	*temp;

	while (list != NULL)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
	free(list);
	free(utils->original_arr);
	free(utils->ordered_arr);
}

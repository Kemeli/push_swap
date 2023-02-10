/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:02:08 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/02/08 00:30:18 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	list_size(t_stack *lst)
{
	int		length;
	t_stack	*aux_lst;

	length = 0;
	aux_lst = lst;
	while (aux_lst)
	{
		aux_lst = aux_lst->next;
		length++;
	}
	return (length);
}

t_stack	*create_list(t_stack *list, t_stack *new_node, t_utils *utils)
{
	t_stack	*aux;

	if (utils->check == 0)
	{
		list = new_node;
		utils->check = 1;
	}
	else
	{
		aux = list;
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = new_node;
	}
	utils->len_a++;
	return (list);
}

static int	get_index(t_stack *new_node, int *ordered_arr)
{
	int	i;

	i = 0;
	while (new_node->value != ordered_arr[i])
		i++;
	if (new_node->value == ordered_arr[i])
		return (i);
	return (0);
}

t_stack	*get_list_num(t_stack *list, t_utils *utils, int size)
{
	t_stack	*new_node;
	int		i;

	i = 0;
	while (i <= size)
	{
		new_node = ft_calloc(sizeof(t_stack), 1);
		new_node->value = utils->original_arr[i];
		new_node->index = get_index(new_node, utils->ordered_arr);
		list = create_list(list, new_node, utils);
		i++;
	}
	return (list);
}

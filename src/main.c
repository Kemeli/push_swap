/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:48:06 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/02/08 00:36:20 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_utils	utils;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	start_values(&utils, argv, argc);
	check_args(argc, argv, &utils);
	order_array(utils.ordered_arr, 0, utils.size - 1);
	a = get_list_num(a, &utils, utils.size - 1);
	if (!ordered_stack(a))
		sort_numbers(&a, &b, argc - 1, &utils);
	free_stuff(a, &utils);
}

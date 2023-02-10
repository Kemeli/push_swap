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

void	start_values(t_utils *utils, char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	utils->check = 0;
	utils->size = argc - 1;
	utils->original_arr = malloc(sizeof(int) * utils->size);
	utils->ordered_arr = malloc(sizeof(int) * utils->size);
	utils->len_a = 0;
	while (argv[i])
	{
		utils->ordered_arr[j] = ft_atoi(argv[i]);
		utils->original_arr[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
}

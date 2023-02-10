/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:47:22 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/02/08 00:51:41 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_integer(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (!ft_strchr("0123456789", argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_double(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (arr[i] != arr[j] && j < size)
			j++;
		if (arr[i] == arr[j])
			return (0);
		i++;
	}
	return (1);
}

int	bigger_int(char **arr, int i)
{
	int				j;
	int				neg;
	unsigned int	value;

	j = 0;
	neg = 0;
	while (arr[i])
	{
		if (ft_strlen(arr[i]) > 11)
			return (0);
		if (ft_strlen(arr[i]) >= 10)
		{
			if (arr[i][j] == '-' || arr[i][j] == '+')
			{
				if (arr[i][j] == '-')
					neg = 1;
				j++;
			}
			value = (unsigned int)ft_atoi(&arr[i][j]);
			if (((value > INT_MIN) && neg) || ((value > INT_MAX) && !neg))
				return (0);
		}
		i++;
	}
	return (1);
}

void	error_message(t_utils *utils)
{
	free(utils->original_arr);
	free(utils->ordered_arr);
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

void	check_args(int argc, char **argv, t_utils *utils)
{
	if (argc < 2)
	{
		free(utils->original_arr);
		free(utils->ordered_arr);
		exit (0);
	}
	if (!check_integer(argv))
		error_message(utils);
	if (!bigger_int(argv, 1))
		error_message(utils);
	if (!check_double(utils->original_arr, utils->size - 1))
		error_message(utils);
}

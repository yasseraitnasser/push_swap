/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:43:37 by yait-nas          #+#    #+#             */
/*   Updated: 2024/04/23 15:15:50 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_args_helper(char **argv, int i)
{
	int	j;
	int	flag;

	j = 0;
	flag = 0;
	while (argv[i][j])
	{
		if (ft_isdigit(argv[i][j]) || argv[i][j] == ' '
				|| argv[i][j] == '+' || argv[i][j] == '-')
		{
			if (argv[i][j] == '+' || argv[i][j] == '-')
			{
				if ((j && argv[i][j - 1] != ' ')
						|| !ft_isdigit(argv[i][j + 1]))
					error();
			}
			else if (ft_isdigit(argv[i][j]))
				flag++;
			j++;
		}
		else
			error();
	}
	if (!flag)
		error();
}

void	check_args(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (!argv[i][0])
			error();
		check_args_helper(argv, i);
	}
}

void	first_check(long number, long *numbers)
{
	if (number > INT_MAX || number < INT_MIN)
	{
		free(numbers);
		error();
	}
}

void	last_check(long *numbers, int count)
{
	int	i;

	i = 0;
	while (i < count - 1)
	{
		if (numbers[i] > numbers[i + 1])
			break ;
		i++;
	}
	if (i == count - 1)
	{
		free(numbers);
		exit(EXIT_SUCCESS);
	}
}

void	check_numbers(long *numbers, int count)
{
	int	i;
	int	j;

	i = -1;
	while (++i < count)
	{
		first_check(numbers[i], numbers);
		if (i < count - 1)
		{
			j = i + 1;
			while (j < count)
			{
				if (numbers[i] == numbers[j])
				{
					free(numbers);
					error();
				}
				j++;
			}
		}
	}
	last_check(numbers, count);
}

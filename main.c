/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:05:10 by yait-nas          #+#    #+#             */
/*   Updated: 2024/04/23 17:48:50 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	next_10(const char *str, int i, long *numbers, char **ptr)
{
	int	digits;

	digits = 0;
	while (str[i] && ft_isdigit(str[i]))
	{
		digits++;
		i++;
	}
	if (digits > 10)
	{
		free_one(ptr);
		free(numbers);
		error();
	}
}

void	sort_list(t_list **stack_a, int count)
{
	t_list	*stack_b;

	stack_b = NULL;
	if (count <= 3)
		sort_3_or_less(stack_a, count);
	else if (count <= 5)
		sort_5_or_less(stack_a, &stack_b, count);
	else
		sort_everything(stack_a, &stack_b, count);
}

void	push_swap(long *numbers, int count)
{
	t_list	*stack_a;

	stack_a = NULL;
	creat_list(&stack_a, numbers, count);
	list_init(&stack_a, count);
	sort_list(&stack_a, count);
	free_list(stack_a);
}

int	main(int argc, char **argv)
{
	char	*args_joined;
	char	**args_splited;
	long	*numbers;
	int		count;

	if (argc > 1)
	{
		check_args(argv);
		args_joined = join_them_all(argv);
		args_splited = ft_split(args_joined, ' ', &count);
		free(args_joined);
		numbers = get_numbers(args_splited, count);
		free_one(args_splited);
		check_numbers(numbers, count);
		if (count > 1)
			push_swap(numbers, count);
		free(numbers);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:40:13 by yait-nas          #+#    #+#             */
/*   Updated: 2024/04/24 22:05:19 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push_swap_bonus(long *numbers, int count)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		new_count;
	char	*str;

	stack_a = NULL;
	stack_b = NULL;
	str = NULL;
	creat_list(&stack_a, numbers, count);
	apply_instruction(&stack_a, &stack_b, str);
	new_count = count_again(stack_a);
	if (is_sorted(stack_a) && new_count == count)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_list(stack_a);
	free_list(stack_b);
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
		push_swap_bonus(numbers, count);
		free(numbers);
	}
	return (0);
}

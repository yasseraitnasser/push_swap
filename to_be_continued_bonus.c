/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_be_continued_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:09:27 by yait-nas          #+#    #+#             */
/*   Updated: 2024/04/24 22:08:52 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	clean_exit(t_list *stack_a, t_list *stack_b, char *inst)
{
	free_list(stack_a);
	free_list(stack_b);
	free(inst);
	error();
}

int	handle_instraction(t_list **stack_a, t_list **stack_b, char *instruction)
{
	if (!ft_strcmp(instruction, "sa\n"))
		sa(stack_a);
	else if (!ft_strcmp(instruction, "sb\n"))
		sb(stack_b);
	else if (!ft_strcmp(instruction, "ss\n"))
		ss(stack_a, stack_b);
	else if (!ft_strcmp(instruction, "ra\n"))
		ra(stack_a);
	else if (!ft_strcmp(instruction, "rb\n"))
		rb(stack_b);
	else if (!ft_strcmp(instruction, "rr\n"))
		rr(stack_a, stack_b);
	else if (!ft_strcmp(instruction, "pa\n"))
		pa(stack_a, stack_b);
	else if (!ft_strcmp(instruction, "pb\n"))
		pb(stack_a, stack_b);
	else if (!ft_strcmp(instruction, "rra\n"))
		rra(stack_a);
	else if (!ft_strcmp(instruction, "rrb\n"))
		rrb(stack_b);
	else if (!ft_strcmp(instruction, "rrr\n"))
		rrr(stack_a, stack_b);
	else
		return (0);
	return (1);
}

void	apply_instruction(t_list **stack_a, t_list **stack_b, char *instruction)
{
	instruction = get_next_line(0);
	while (instruction)
	{
		if (handle_instraction(stack_a, stack_b, instruction))
		{
			free(instruction);
			instruction = get_next_line(0);
			continue ;
		}
		else
			clean_exit(*stack_a, *stack_b, instruction);
	}
}

int	count_again(t_list *stack_a)
{
	int	new_count;

	new_count = 0;
	while (stack_a)
	{
		new_count++;
		stack_a = stack_a -> next;
	}
	return (new_count);
}

int	is_sorted(t_list *stack_a)
{
	if (!stack_a)
		return (0);
	while (stack_a -> next)
	{
		if (stack_a -> content > stack_a -> next -> content)
			return (0);
		stack_a = stack_a -> next;
	}
	return (1);
}

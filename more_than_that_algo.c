/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_than_that_algo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:28:53 by yait-nas          #+#    #+#             */
/*   Updated: 2024/04/23 14:39:04 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dont_forget_rb(t_list **a, t_list **b, t_list *tmp, int count)
{
	if (tmp -> cur_pos <= count / 2)
	{
		while (*a != tmp)
			ra(a);
		pb(a, b);
		rb(b);
	}
	else
	{
		while (*a != tmp)
			rra(a);
		pb(a, b);
		rb(b);
	}
	update_position(a);
}

void	just_push(t_list **stack_a, t_list **stack_b, t_list *tmp, int count)
{
	if (tmp -> cur_pos <= count / 2)
	{
		while (*stack_a != tmp)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	else
	{
		while (*stack_a != tmp)
			rra(stack_a);
		pb(stack_a, stack_b);
	}
	update_position(stack_a);
}

void	reset(int *min, int *max, t_list **tmp, t_list *head)
{
	(*min)++;
	(*max)++;
	*tmp = head;
}

void	push_to_b(t_list **stack_a, t_list **stack_b, int count)
{
	int		min;
	int		max;
	t_list	*tmp;

	min = 1;
	max = ft_sqrt(count) + count / 500 + 5;
	update_position(stack_a);
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp -> rank < min)
		{
			dont_forget_rb(stack_a, stack_b, tmp, count);
			reset(&min, &max, &tmp, *stack_a);
			continue ;
		}
		else if (tmp -> rank >= min && tmp -> rank <= max)
		{
			just_push(stack_a, stack_b, tmp, count);
			reset(&min, &max, &tmp, *stack_a);
			continue ;
		}
		tmp = tmp -> next;
	}
}

void	sort_everything(t_list **stack_a, t_list **stack_b, int count)
{
	push_to_b(stack_a, stack_b, count);
	push_back_to_a(stack_a, stack_b, count);
}

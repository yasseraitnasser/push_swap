/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_nbrs_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:19:23 by yait-nas          #+#    #+#             */
/*   Updated: 2024/04/22 16:21:33 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_smallest(t_list **stack_a, t_list **stack_b, int rank)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *stack_a;
	tmp2 = ft_lstlast(*stack_a);
	while (tmp1 && tmp2)
	{
		if (tmp1 && tmp1 -> rank == rank)
		{
			while ((*stack_a)-> rank != rank)
				ra(stack_a);
			pb(stack_a, stack_b);
			break ;
		}
		if (tmp2 && tmp2 -> rank == rank)
		{
			while ((*stack_a)-> rank != rank)
				rra(stack_a);
			pb(stack_a, stack_b);
			break ;
		}
		tmp1 = tmp1 -> next;
		tmp2 = tmp2 -> previous;
	}
}

void	sort_5_or_less(t_list **stack_a, t_list **stack_b, int count)
{
	if (count == 4)
	{
		push_smallest(stack_a, stack_b, 1);
		sort_3_or_less(stack_a, count);
		pa(stack_a, stack_b);
	}
	else
	{
		push_smallest(stack_a, stack_b, 1);
		push_smallest(stack_a, stack_b, 2);
		sort_3_or_less(stack_a, count);
		if ((*stack_b)-> content < (*stack_b)-> next -> content)
			sb(stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}

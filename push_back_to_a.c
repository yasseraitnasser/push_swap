/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:16:41 by yait-nas          #+#    #+#             */
/*   Updated: 2024/04/23 14:17:30 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a(t_list **stack_a, t_list **stack_b, t_list *tmp, int count)
{
	if (tmp -> cur_pos <= count / 2)
	{
		while (*stack_b != tmp)
			rb(stack_b);
		pa(stack_a, stack_b);
	}
	else
	{
		while (*stack_b != tmp)
			rrb(stack_b);
		pa(stack_a, stack_b);
	}
}

void	best_price1(t_list **a, t_list **b, t_list **tmp1, t_list **tmp2)
{
	t_list	*tmp;

	tmp = *tmp1;
	while (*b != tmp)
		rb(b);
	pa(a, b);
	*tmp1 = *b;
	*tmp2 = ft_lstlast(*b);
}

void	best_price2(t_list **a, t_list **b, t_list **tmp1, t_list **tmp2)
{
	t_list	*tmp;

	tmp = *tmp2;
	while (*b != tmp)
		rrb(b);
	pa(a, b);
	*tmp1 = *b;
	*tmp2 = ft_lstlast(*b);
}

void	push_back_to_a(t_list **stack_a, t_list **stack_b, int count)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *stack_b;
	tmp2 = ft_lstlast(*stack_b);
	while (tmp1 && tmp2)
	{
		if (tmp1 -> rank == count)
		{
			best_price1(stack_a, stack_b, &tmp1, &tmp2);
			count--;
			continue ;
		}
		if (tmp2 -> rank == count)
		{
			best_price2(stack_a, stack_b, &tmp1, &tmp2);
			count--;
			continue ;
		}
		tmp1 = tmp1 -> next;
		tmp2 = tmp2 -> previous;
	}
}

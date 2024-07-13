/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:55:30 by yait-nas          #+#    #+#             */
/*   Updated: 2024/04/22 16:55:42 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stack_a)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (stack_a && *stack_a && (*stack_a)-> next)
	{
		tmp1 = ft_lstlast(*stack_a);
		tmp2 = *stack_a;
		while (tmp2 -> next -> next)
			tmp2 = tmp2 -> next;
		tmp2 -> next = NULL;
		tmp1 -> previous = NULL;
		tmp1 -> next = *stack_a;
		(*stack_a)->previous = tmp1;
		*stack_a = tmp1;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_list **stack_b)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (stack_b && *stack_b)
	{
		tmp1 = ft_lstlast(*stack_b);
		tmp2 = *stack_b;
		while (tmp2 -> next -> next)
			tmp2 = tmp2 -> next;
		tmp2 -> next = NULL;
		tmp1 -> previous = NULL;
		tmp1 -> next = *stack_b;
		(*stack_b)-> previous = tmp1;
		*stack_b = tmp1;
		write(1, "rrb\n", 4);
	}
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (stack_b && *stack_b)
	{
		tmp = *stack_b;
		(*stack_b) = (*stack_b)-> next;
		if (*stack_b)
			(*stack_b)-> previous = NULL;
		tmp -> next = *stack_a;
		if (*stack_a)
			(*stack_a)-> previous = tmp;
		*stack_a = tmp;
		write(1, "pa\n", 3);
	}
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (stack_a && *stack_a)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)-> next;
		if (*stack_a)
			(*stack_a)-> previous = NULL;
		tmp -> next = *stack_b;
		if (*stack_b)
			(*stack_b)-> previous = tmp;
		tmp -> previous = NULL;
		*stack_b = tmp;
		write(1, "pb\n", 3);
	}
}

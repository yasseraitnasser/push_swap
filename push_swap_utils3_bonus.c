/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:16:30 by yait-nas          #+#    #+#             */
/*   Updated: 2024/04/24 19:07:16 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	rotate(t_list **stack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (stack && *stack)
	{
		tmp1 = *stack;
		tmp2 = ft_lstlast(tmp1);
		*stack = (*stack)-> next;
		(*stack)-> previous = NULL;
		tmp1 -> next = NULL;
		tmp1 -> previous = tmp2;
		tmp2 -> next = tmp1;
	}
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void	reverse_rotate(t_list **stack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (stack && *stack && (*stack)-> next)
	{
		tmp1 = ft_lstlast(*stack);
		tmp2 = *stack;
		while (tmp2 -> next -> next)
			tmp2 = tmp2 -> next;
		tmp2 -> next = NULL;
		tmp1 -> previous = NULL;
		tmp1 -> next = *stack;
		(*stack)->previous = tmp1;
		*stack = tmp1;
	}
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}

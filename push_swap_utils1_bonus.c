/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:12:55 by yait-nas          #+#    #+#             */
/*   Updated: 2024/04/24 18:47:45 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_list **stack_a)
{
	t_list	*tmp;

	if (stack_a && *stack_a)
	{
		tmp = (*stack_a)-> next;
		(*stack_a)-> next = (*stack_a)-> next -> next;
		tmp -> next = *stack_a;
		*stack_a = tmp;
	}
}

void	sb(t_list **stack_b)
{
	t_list	*tmp;

	if (stack_b && *stack_b)
	{
		tmp = (*stack_b)-> next;
		(*stack_b)-> next = (*stack_b)-> next -> next;
		tmp -> next = *stack_b;
		*stack_b = tmp;
	}
}

void	ra(t_list **stack_a)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (stack_a && *stack_a)
	{
		tmp1 = *stack_a;
		tmp2 = ft_lstlast(tmp1);
		*stack_a = (*stack_a)-> next;
		(*stack_a)-> previous = NULL;
		tmp1 -> next = NULL;
		tmp1 -> previous = tmp2;
		tmp2 -> next = tmp1;
	}
}

void	rb(t_list **stack_b)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (stack_b && *stack_b)
	{
		tmp1 = *stack_b;
		tmp2 = ft_lstlast(tmp1);
		*stack_b = (*stack_b)-> next;
		(*stack_b)-> previous = NULL;
		tmp1 -> next = NULL;
		tmp1 -> previous = tmp2;
		tmp2 -> next = tmp1;
	}
}

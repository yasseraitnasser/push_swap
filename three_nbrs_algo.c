/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_nbrs_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:17:34 by yait-nas          #+#    #+#             */
/*   Updated: 2024/04/23 16:22:06 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_helper(t_list **stack_a, t_list *first, t_list *sec, t_list *last)
{
	if (first->content < sec->content && first->content < last->content)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (last->content < first->content && last->content < sec->content)
	{
		if (first -> content < sec -> content)
			rra(stack_a);
		else
		{
			sa(stack_a);
			rra(stack_a);
		}
	}
	else
	{
		if (first -> content < last -> content)
			sa(stack_a);
		else
			ra(stack_a);
	}
}

int	is_sorted(t_list *head)
{
	t_list	*tmp;

	tmp = ft_lstlast(head);
	while (head -> next)
	{
		if (head -> content > head -> next -> content)
			break ;
		head = head -> next;
	}
	if (tmp == head)
		return (1);
	return (0);
}

void	sort_3_or_less(t_list **stack_a, int count)
{
	t_list	*first;
	t_list	*last;
	t_list	*second;

	first = *stack_a;
	second = (*stack_a)-> next;
	last = ft_lstlast(first);
	if (count == 2)
		sa(stack_a);
	else if (!is_sorted(*stack_a))
		sort_helper(stack_a, first, second, last);
}

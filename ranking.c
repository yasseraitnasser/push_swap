/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:08:09 by yait-nas          #+#    #+#             */
/*   Updated: 2024/04/22 17:08:39 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_unranked_min(t_list *stack_a)
{
	int	min;

	min = INT_MAX;
	while (stack_a)
	{
		if (!(stack_a -> already_ranked))
		{
			if (min > stack_a -> content)
				min = stack_a -> content;
		}
		stack_a = stack_a -> next;
	}
	return (min);
}

void	rank_numbers(t_list **stack_a, int count)
{
	int		min;
	int		rank;
	t_list	*tmp;
	int		i;

	i = 0;
	rank = 1;
	while (i < count)
	{
		tmp = *stack_a;
		min = find_unranked_min(tmp);
		while (tmp)
		{
			if (tmp -> content == min)
			{
				tmp -> rank = rank;
				rank++;
				tmp -> already_ranked = 1;
				break ;
			}
			tmp = tmp -> next;
		}
		i++;
	}
}

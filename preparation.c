/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:02:05 by yait-nas          #+#    #+#             */
/*   Updated: 2024/04/23 15:07:54 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join_them_all(char **argv)
{
	int		i;
	char	*tmp;
	char	*result;

	i = 2;
	result = ft_strdup(argv[1]);
	while (argv[i])
	{
		tmp = result;
		result = ft_strjoin3(result, " ", argv[i]);
		free(tmp);
		i++;
	}
	return (result);
}

long	*get_numbers(char **ptr, int count)
{
	int		i;
	long	*result;

	result = malloc(sizeof(long int) * count);
	i = 0;
	while (ptr[i])
	{
		result[i] = ft_atoi(ptr[i], result, ptr);
		i++;
	}
	return (result);
}

void	update_position(t_list **stack)
{
	t_list	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp -> cur_pos = i;
		i++;
		tmp = tmp -> next;
	}
}

void	list_init(t_list **stack_a, int count)
{
	t_list	*tmp;
	int		i;

	tmp = *stack_a;
	i = 0;
	while (tmp)
	{
		tmp -> already_ranked = 0;
		tmp -> cur_pos = i;
		i++;
		tmp = tmp -> next;
	}
	rank_numbers(stack_a, count);
}

void	creat_list(t_list **stack_a, long *numbers, int count)
{
	int		i;
	t_list	*node;

	i = 0;
	while (i < count)
	{
		node = ft_lstnew(numbers[i]);
		ft_lstadd_back(stack_a, node);
		i++;
	}
}

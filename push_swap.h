/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:55:46 by yait-nas          #+#    #+#             */
/*   Updated: 2024/04/23 21:59:39 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <limits.h>
# include <math.h>

typedef struct s_list
{
	int				content;
	int				rank;
	int				already_ranked;
	int				cur_pos;
	struct s_list	*previous;
	struct s_list	*next;
}	t_list;

int		ft_isdigit(int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin3(char *s1, char *s2, char *s3);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	**ft_split(char const	*s, char c, int *count);
long	ft_atoi(const char *str, long *numbers, char **ptr);
void	free_one(char **ptr);
void	error(void);
void	check_args(char **argv);
void	check_numbers(long *numbers, int count);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	first_check(long number, long *numbers);
void	last_check(long *numbers, int count);
void	next_10(const char *str, int i, long *numbers, char **ptr);
void	free_list(t_list *head);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
int		ft_sqrt(int nb);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
void	sort_3_or_less(t_list **stack_a, int count);
void	sort_helper(t_list **stack_a, t_list *first, t_list *sec, t_list *last);
void	sort_5_or_less(t_list **stack_a, t_list **stack_b, int count);
void	push_smallest(t_list **stack_a, t_list **stack_b, int rank);
void	sort_everything(t_list **stack_a, t_list **stack_b, int count);
void	rank_numbers(t_list **stack_a, int count);
int		find_unranked_min(t_list *stack_a);
void	creat_list(t_list **stack_a, long *numbers, int count);
void	list_init(t_list **stack_a, int count);
void	update_position(t_list **stack);
long	*get_numbers(char **ptr, int count);
char	*join_them_all(char **argv);
void	push_back_to_a(t_list **stack_a, t_list **stack_b, int count);
void	best_price2(t_list **a, t_list **b, t_list **tmp1, t_list **tmp2);
void	best_price1(t_list **a, t_list **b, t_list **tmp1, t_list **tmp2);
void	push_to_a(t_list **stack_a, t_list **stack_b, t_list *tmp, int count);
int		is_sorted(t_list *head);

#endif

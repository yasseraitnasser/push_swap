/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:31:21 by yait-nas          #+#    #+#             */
/*   Updated: 2024/04/24 21:21:42 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <limits.h>
# include <math.h>
# include "get_next_line/get_next_line.h"

typedef struct s_list
{
	int				content;
	int				rank;
	int				already_ranked;
	int				cur_pos;
	struct s_list	*previous;
	struct s_list	*next;
}	t_list;

void	check_args(char **argv);
void	check_args_helper(char **argv, int i);
void	check_numbers(long *numbers, int count);
void	first_check(long number, long *numbers);
void	last_check(long *numbers, int count);
char	*join_them_all(char **argv);
long	*get_numbers(char **ptr, int count);
void	creat_list(t_list **stack_a, long *numbers, int count);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_isdigit(int c);
void	free_one(char **ptr);
void	free_list(t_list *head);
long	ft_atoi(const char *str, long *numbers, char **ptr);
t_list	*ft_lstnew(int content);
char	**ft_split(char const	*s, char c, int *count);
char	*ft_strjoin3(char *s1, char *s2, char *s3);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
void	error(void);
void	next_10(const char *str, int i, long *numbers, char **ptr);
t_list	*ft_lstlast(t_list *lst);
char	*ft_strdup(const char *s1);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	swap(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);
void	rotate(t_list **stack);
void	rr(t_list **stack_a, t_list **stack_b);
void	reverse_rotate(t_list **stack);
void	rrr(t_list **stack_a, t_list **stack_b);
int		ft_strcmp(const char *s1, const char *s2);
void	apply_instruction(t_list **stack_a, t_list **stack_b, char *str);
int		count_again(t_list *stack_a);
int		is_sorted(t_list *stack_a);
void	next_10(const char *str, int i, long *numbers, char **ptr);
void	clean_exit(t_list *stack_a, t_list *stack_b, char *inst);
int		handle_instruction(t_list **a, t_list **b, char *instruction);

#endif

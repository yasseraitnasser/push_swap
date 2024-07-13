/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:21:13 by yait-nas          #+#    #+#             */
/*   Updated: 2024/04/24 19:05:32 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

typedef struct s_linked
{
	char			*content;
	struct s_linked	*next;
}	t_linked;

t_linked	*ft_lst_last(t_linked *list);
int			found_newline(t_linked *list);
void		add_up(t_linked **list, char *buf);
void		creat_linked(t_linked **list, int fd);
int			len_to_newline(t_linked *list);
void		my_strcpy(t_linked *list, char *buf);
char		*get_line_y(t_linked *list);
void		free_check(t_linked **list, t_linked *clean_node, char *buf);
void		clean_up(t_linked **list);
char		*get_next_line(int fd);

#endif

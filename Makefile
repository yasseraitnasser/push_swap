# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 15:02:39 by yait-nas          #+#    #+#              #
#    Updated: 2024/04/24 22:11:40 by yait-nas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAMEB = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror 
FILES = main.c ft_strjoin3.c ft_strdup.c ft_strlen.c \
	ft_strlcat.c ft_strlcpy.c ft_split.c ft_atoi.c \
	error.c free.c checks.c ft_lstnew.c ft_lstadd_back.c \
	ft_lstlast.c ft_isdigit.c push_swap_utils1.c \
	ft_sqrt.c ft_strncmp.c five_nbrs_algo.c three_nbrs_algo.c \
	more_than_that_algo.c push_swap_utils2.c ranking.c preparation.c \
	push_back_to_a.c

BONUS = main_bonus.c checks_bonus.c free_bonus.c ft_atoi_bonus.c \
	ft_isdigit_bonus.c ft_lstadd_back_bonus.c ft_lstnew_bonus.c ft_split_bonus.c \
	ft_strjoin3_bonus.c ft_strlcat_bonus.c ft_strlcpy_bonus.c ft_strlen_bonus.c \
	ft_strncmp_bonus.c preparation_bonus.c ft_lstlast_bonus.c ft_strdup_bonus.c \
	error_bonus.c push_swap_utils1_bonus.c push_swap_utils2_bonus.c push_swap_utils3_bonus.c \
	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c ft_strcmp_bonus.c \
	to_be_continued_bonus.c

FILES_o = $(FILES:.c=.o)
BONUS_o = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(FILES_o)
	$(CC) $(CFLAGS) $(FILES_o) -o $(NAME)

bonus: $(NAMEB)

$(NAMEB): $(BONUS_o)
	$(CC) $(CFLAGS) $(BONUS_o) -o $(NAMEB)

clean:
	rm -f $(FILES_o) $(BONUS_o)

fclean: clean
	rm -f $(NAME) $(NAMEB)

re: fclean all

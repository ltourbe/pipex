# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltourbe <ltourbe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/07 18:39:42 by ltourbe           #+#    #+#              #
#    Updated: 2026/01/07 18:43:02 by ltourbe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS		= -Wall -Wextra -Werror

SRCS		= ft_printf.c \
		  ft_split.c \
		  ft_strjoin.c \
		  ft_tools.c \
		  ft_tools2.c \
		  pipex_utils.c \
		  pipex.c \

OBJS		= $(patsubst %.c, %.o, $(SRCS))

NAME		= pipex.a

all:		$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o:		%.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f $(OBJS)

fclean:		clean
	rm -f $(NAME)

re:		fclean all

.PHONY:	clean fclean all
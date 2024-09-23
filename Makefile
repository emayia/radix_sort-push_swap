# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 17:18:57 by mayyildi          #+#    #+#              #
#    Updated: 2022/10/14 18:30:48 by mayyildi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS	=	push_swap.c					\
			minilib/ft_atoi.c			\
			minilib/ft_isdigit.c		\
			minilib/ft_lstadd_back.c	\
			minilib/ft_lstlast.c		\
			minilib/ft_lstnew.c			\
			minilib/ft_lstsize.c		\
			minilib/ft_split.c			\
			moves/push.c				\
			moves/swap.c				\
			moves/rotate.c				\
			moves/reverse_rotate.c		\
			sorting/radix_sort.c		\
			sorting/small_sort.c		\
			stacks/checks.c				\
			stacks/indices.c			\
			stacks/op.c					\
			utils/errors.c				\
			utils/mem.c					\

OBJS	= ${SRCS:.c=.o}

CC		=	gcc

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror # -fsanitize=address -g

all:		${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}
clean:
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

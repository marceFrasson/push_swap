# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/27 18:38:37 by mfrasson          #+#    #+#              #
#    Updated: 2021/11/27 18:49:38 by mfrasson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC		=	source/checkings.c \
			source/moves_I.c \
			source/moves_II.c \
			source/push_swap.c \
			source/radix_sort.c \
			source/small_sort.c \
			source/steps.c

OBJ		=	${SRC:.c=.o}

INCD	=	includes/push_swap.h

NAME	=	push_swap

MODULE	=	./libft/libft.a

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -rf

CC		=	clang

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}
	echo "  Criando .o de "$<

all:			$(NAME)

$(NAME):	$(MODULE) $(OBJ) $(INCD)
	$(CC) $(CFLAGS) $(OBJ) $(MODULE) -o $(NAME)
$(MODULE):
	make -C libft

clean:
	$(RM) $(OBJ)
	make clean -C libft

fclean:		clean
	$(RM) $(NAME)
	make fclean -C libft

re:			fclean all

git:
	git add .
	git status
	git commit -m "$m"

.PHONY:		all clean fclean re git

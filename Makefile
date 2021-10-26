# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/15 10:51:58 by mfrasson          #+#    #+#              #
#    Updated: 2021/10/15 10:54:43 by mfrasson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	algorithm.c checkings.c moves_I.c moves_II.c push_swap.c /
			steps.c utils.c

OBJ		=	${SRC:.c=.o}
#--------------------------------------//---------------------------------------

NAME		=	push_swap

INCLUDE		=	-I includes -I libft

MODULE		=	./libft/libft.a

FLAGS		=	-Wall -Wextra -Werror

MLX_FLAGS	=	-lbsd -lmlx -lXext -lX11 -lm

CC			=	clang
#--------------------------------------//---------------------------------------
.c.o:
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o}
#--------------------------------------//---------------------------------------
all:		$(NAME)

$(MODULE):
	@make -C libft

$(NAME):	$(MODULE) $(OBJ)
	@$(CC) $(OBJ) $(FLAGS) $(INCLUDE) $(MODULE) $(MLX_FLAGS) -o $(NAME)
	@echo ""
	@echo "|            push_swap criado           |"
	@echo ""
#--------------------------------------//---------------------------------------
clean:
	@rm -rf $(OBJ)
	@make clean -C libft

fclean:		clean
	@rm -rf $(NAME)
	@make fclean -C libft
	@echo ""
	@echo "|           push_swap deletado          |"
	@echo ""
#--------------------------------------//---------------------------------------

re:			fclean all

git:
	git add .
	git status
	git commit -m "$m"
	git push

.PHONY:		all clean fclean re git
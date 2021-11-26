#--------------------------------------//---------------------------------------
SRC		=	checkings.c error.c moves_I.c moves_II.c \
			push_swap.c radix_sort.c small_sort.c steps.c utils.c

OBJ		=	${SRC:.c=.o}

INCD	=	push_swap.h
#--------------------------------------//---------------------------------------
NAME	=	push_swap

MODULE	=	./libft/libft.a

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -rf

CC		=	clang
#--------------------------------------//---------------------------------------
.c.o:
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o}
	@echo "  Criando .o de "$<
#--------------------------------------//---------------------------------------
all:			$(NAME)

$(NAME):	$(MODULE) $(OBJ) $(INCD)
	$(CC) $(CFLAGS) $(OBJ) $(MODULE) -o $(NAME)
	@echo ""
	@echo "/ ************************************ \\"
	@echo "|           Push_Swap Criado           |"
	@echo "\\ ************************************ /"
	@echo ""

$(MODULE):
	make -C libft
#--------------------------------------//---------------------------------------
clean:
	$(RM) $(OBJ)
	make clean -C libft
	@echo ""
	@echo "/ ************************************ \\"
	@echo "|        Arquivos .o Deletados         |"
	@echo "\\ ************************************ /"
	@echo ""

fclean:		clean
	$(RM) $(NAME)
	make fclean -C libft
	@echo ""
	@echo "/ ************************************ \\"
	@echo "|          minishell Deletado          |"
	@echo "\\ ************************************ /"
	@echo ""
#--------------------------------------//---------------------------------------
re:			fclean all

git:
	@git add .
	@git status
	@git commit -m "$m"

.PHONY:		all clean fclean re git

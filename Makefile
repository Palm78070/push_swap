NAME = push_swap

LIB = ./libft/libft.a
LIB_I = ./libft/

CFLAGS = -Wall -Werror -Wextra 

SRCS = main.c \
       utils.c \
       utils2.c \
       utils3.c \
       utils4.c \
       utils5.c \
       merge_sort.c \
       instruct.c \

all: $(NAME)

libft:
	@make -C ./libft

$(NAME): libft
	@gcc -o $(NAME) $(CFLAGS) -g -I$(LIB_I) $(LIB) $(SRCS)

norminette:
	norminette -R CheckForbiddenHeader *.h *.c

clean:
	@make clean -C ./libft
	rm -rf *.dSYM $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re libft

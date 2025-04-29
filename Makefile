CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = minishell

PATH1 = Libft/libft.a

FILES = src/minishell.c

OB = $(FILES:.c=.o)

all : $(PATH1) $(NAME)

$(PATH1):
		$(MAKE) -C Libft

$(NAME) : $(OB)
		$(CC) $(CFLAGS) -o $(NAME) $(OB) $(PATH1) -lreadline

%.o : %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OB)
		$(MAKE) clean -C Libft

fclean : clean
		rm -f $(NAME)
		$(MAKE) clean -C Libft

re : fclean all

.PHONY : clean fclean all re

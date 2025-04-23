CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = minishell

FILES = src/

OB = $(FILES:.c=.o)

all : $(NAME)

$(NAME) : $(OB)
		$(CC) $(CFLAGS) -o $(NAME) $(OB)

%.o : %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OB)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY : clean fclean all re

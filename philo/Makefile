NAME= philo
SRC= $(wildcard src/*.c)
OBJ= $(SRC:.c=.o)
CFLAGS= -Wall -Wextra -Werror
CC= gcc -g -lpthread

all: $(NAME)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(NAME): $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
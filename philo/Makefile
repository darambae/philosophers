NAME= philo
SRC=
OBJ= $(SRC:.c=.o)
CFLAGS= -Wall -Wextra -Werror
CC= gcc -g -pthread (-lpthread for linux)

all: $(NAME)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

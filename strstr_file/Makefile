CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

SRC = errors.c file.c inputs.c main.c maths.c strings.c strings2.c structs.c directory.c

HEADERS = strstr.h

OBJ = $(SRC:.c=.o)

NAME = search

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

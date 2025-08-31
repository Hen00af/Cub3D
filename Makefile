NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./lib
SRC_DIR = ./src
SRC = $(SRC_DIR)/main.c $(SRC_DIR)/parse.c
OBJ = $(SRC:.c=.o)
HEADER = ./lib/cub3D.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -lm

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
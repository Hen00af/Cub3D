NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./lib -I./libft
SRC_DIR = ./src
SRC = $(SRC_DIR)/main.c $(SRC_DIR)/parse.c
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
OBJ = $(SRC:.c=.o)
HEADER = ./lib/cub3D.h

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) -lm

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) 
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re 
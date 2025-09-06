NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./lib -I./libft -I./get_next_line
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
GNL_DIR = ./get_next_line
GNL = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
SRC_DIR = ./src
SRC = $(SRC_DIR)/main.c $(SRC_DIR)/parse_args.c $(SRC_DIR)/parse_maps.c  $(SRC_DIR)/utils.c  $(SRC_DIR)/exit.c  $(SRC_DIR)/validation.c
OBJ = $(SRC:.c=.o) $(GNL:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re 
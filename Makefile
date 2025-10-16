NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./lib -I./src/game -I./src/parse -I./get_next_line -I./libft -I./minilibx-linux

LIBFT = libft/libft.a
PARSE = src/parse/parse.a
GAME  = src/game/game.a
GNL   = get_next_line/gnl.a
MISC  = src/misc/init_game.o

all: $(NAME)

$(NAME): main.o $(MISC) $(PARSE) $(GAME) $(GNL) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ -Lminilibx-linux -lmlx -lXext -lX11 -lm

main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

src/misc/init_game.o: src/misc/init_game.c
	$(CC) $(CFLAGS) -c $< -o $@

v:
	$(MAKE) -C src/parse

$(LIBFT):
	$(MAKE) -C libft
$(PARSE):
	$(MAKE) -C src/parse
$(GAME):
	$(MAKE) -C src/game
$(GNL):
	$(MAKE) -C get_next_line

j:
	$(MAKE) -j all

clean:
	$(MAKE) -C libft clean
	$(MAKE) -C src/parse clean
	$(MAKE) -C src/game clean
	$(MAKE) -C get_next_line clean
	rm -f main.o $(MISC)

fclean: clean
	$(MAKE) -C libft fclean
	$(MAKE) -C src/parse fclean
	$(MAKE) -C src/game fclean
	$(MAKE) -C get_next_line fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

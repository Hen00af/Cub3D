NAME = game

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./lib -I./libft -I./get_next_line

MLXFLAGS = -L minilibx-Linux -lmlx -lXext -lX11 -lm

SRC = main.c \
      init/init_game.c \
      key_operation/handle_key.c \
	  key_operation/move.c \
      render/render_algo.c \
      render/render.c \
      utils/utils.c
	  
OBJDIR = obj
OBJ = $(patsubst %.c,$(OBJDIR)/%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLXFLAGS) -o $(NAME)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

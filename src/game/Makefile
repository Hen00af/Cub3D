NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./lib -I./libft -I./get_next_line

MLXFLAGS = -L minilibx-Linux -lmlx -lXext -lX11 -lm

SRC = $(wildcard ./*.c)
OBJDIR = obj
OBJ = $(patsubst %.c,$(OBJDIR)/%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLXFLAGS) -o $(NAME)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

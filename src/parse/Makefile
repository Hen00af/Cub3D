NAME = parse.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I../../lib -I../../libft -I../../get_next_line

SRC = check_texture_new.c \
      get_map.c \
      get_map_info.c \
      parse_args.c \
      parse_maps.c \
      utils.c \
      valid_map.c \
      exit_invalid_maps.c

OBJDIR = obj
OBJ = $(patsubst %.c,$(OBJDIR)/%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

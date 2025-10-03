NAME = gnl.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

SRC = get_next_line.c get_next_line_utils.c
OBJDIR = obj
OBJ = $(patsubst %.c,$(OBJDIR)/%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^

# 重要: 「$<」はカレントの .c を指すので必ず get_next_line/ ディレクトリで動く
$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

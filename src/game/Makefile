NAME = game.a
BONUS_NAME  = game_bonus.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./ -I../../libft -I../../get_next_line -I../../lib -I../../minilibx-linux

SRC = game_engine.c \
      init/init_game.c \
      key_operation/handle_key.c \
      key_operation/move.c \
	  render/dda.c \
	  render/init_dda.c \
	  render/utils.c \
	  render/calculate.c \
      render/render.c \
      render/b_render.c \
      utils/close_window.c
	  
OBJDIR = obj
OBJ = $(patsubst %.c,$(OBJDIR)/%.o,$(SRC))


## all field
#

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

#
## all field



## Bonus field
#

bonus: CFLAGS += -D BONUS=1
bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJ)
	@ar rcs $@ $^
#
## Bonus Field 


clean:
	@rm -rf $(OBJDIR)
      
b_fclean: clean
	@rm  -f $(BONUS_NAME)

fclean: clean
	@rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re

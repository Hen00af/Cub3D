NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./lib -I./libft -I./get_next_line

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

GNL_DIR = ./get_next_line
GNL = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c

SRC_DIR = ./src
PARSE_DIR = $(SRC_DIR)/parse
MISC_DIR = $(SRC_DIR)/misc
RENDERING_DIR = $(SRC_DIR)/rendering

SRC = main.c \
      $(PARSE_DIR)/parse_args.c \
      $(PARSE_DIR)/parse_maps.c \
      $(PARSE_DIR)/utils.c \
      $(MISC_DIR)/exit.c \
      $(PARSE_DIR)/exit_invalid_maps.c \
      $(PARSE_DIR)/check_texture_new.c \
	  $(PARSE_DIR)/get_map_info.c \
	  $(PARSE_DIR)/get_map.c \
	  $(PARSE_DIR)/valid_map.c \

OBJ_DIR = ./obj
DEPS_DIR = ./deps

OBJ = $(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o))) \
      $(addprefix $(OBJ_DIR)/,$(notdir $(GNL:.c=.o)))

DEP = $(addprefix $(DEPS_DIR)/,$(notdir $(SRC:.c=.d))) \
      $(addprefix $(DEPS_DIR)/,$(notdir $(GNL:.c=.d)))

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR) $(DEPS_DIR):
	mkdir -p $@

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR) $(DEPS_DIR)
	$(CC) $(CFLAGS) -MMD -MP -MF $(DEPS_DIR)/$*.d -c $< -o $@
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) $(DEPS_DIR)
	$(CC) $(CFLAGS) -MMD -MP -MF $(DEPS_DIR)/$*.d -c $< -o $@
$(OBJ_DIR)/%.o: $(PARSE_DIR)/%.c | $(OBJ_DIR) $(DEPS_DIR)
	$(CC) $(CFLAGS) -MMD -MP -MF $(DEPS_DIR)/$*.d -c $< -o $@
$(OBJ_DIR)/%.o: $(MISC_DIR)/%.c | $(OBJ_DIR) $(DEPS_DIR)
	$(CC) $(CFLAGS) -MMD -MP -MF $(DEPS_DIR)/$*.d -c $< -o $@
$(OBJ_DIR)/%.o: $(RENDERING_DIR)/%.c | $(OBJ_DIR) $(DEPS_DIR)
	$(CC) $(CFLAGS) -MMD -MP -MF $(DEPS_DIR)/$*.d -c $< -o $@
$(OBJ_DIR)/%.o: $(GNL_DIR)/%.c | $(OBJ_DIR) $(DEPS_DIR)
	$(CC) $(CFLAGS) -MMD -MP -MF $(DEPS_DIR)/$*.d -c $< -o $@

debug: CFLAGS += -g
debug: all

valgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) test.cub


clean:
	rm -f $(OBJ) $(DEP)
	rm -rf $(OBJ_DIR) $(DEPS_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re debug valgrind

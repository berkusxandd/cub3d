NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

LIBFT_DIR = libft
SRC_DIR = srcs
OBJ_DIR = obj

PARSER_DIR = $(SRC_DIR)/parser
EVENTS_DIR = $(SRC_DIR)/events
RENDER_DIR = $(SRC_DIR)/render

SRC_FILES = main.c ray.c init_data.c free_data.c mlx_utils.c movement.c movement2.c collision.c hooks.c calculations.c textures.c render_utils.c
PARSER_FILES = check_map.c get_textures.c parser_utils.c parser.c


SRCS =  $(addprefix $(SRC_DIR)/, $(SRC_FILES)) \
		$(addprefix $(PARSER_DIR)/, $(PARSER_FILES)) \
		$(addprefix $(EVENTS_DIR)/, $(EVENTS_FILES)) \

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = mlx
MLX = -L $(MLX_DIR) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm # -lz

INCLUDES = -I includes -I $(LIBFT_DIR) -I $(MLX_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(LIBFT)  -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/parser/%.o: $(PARSER_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/parser
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/events/%.o: $(EVENTS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/events
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/render/%.o: $(RENDER_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/render
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re

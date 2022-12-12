NAME = cub3D

SRC = src/cub3d.c \
	  src/tools.c \
	  src/errors.c \
	  src/check_args.c \
	  src/parse.c \
	  src/parse_resolution.c \
	  src/parse_textures.c \
	  src/parse_colors.c \
	  src/parse_map.c \
	  src/parse_pos.c \
	  src/init_struct.c \
	  src/key_manager.c \
	  src/exit_game.c \
	  src/raycasting.c \
	  src/draw_wall_textures.c \
	  src/draw_ceiling_floor.c \
	  src/get_moves.c \
	  src/parse_sprites.c \
	  src/raycasting_sprites.c \
	  src/bmp.c \
	  src/check_map.c

SAVE = save.bmp

LIBFT = -L./libft -lft
MLX = -L./mlx -lmlx -lXext -lX11 -lm
INC = -I./inc/cub3d.h

CC = clang
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
RM = rm -rf

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	@rm -rf cub3D
	@echo "\033[33m[Last version of $@ was removed]\033[0m"
	@$(MAKE) -C ./libft
	@$(MAKE) -C ./mlx
	@echo "\033[33m[New version of $@ is compiling...]\033[0m"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(INC) $(LIBFT) $(MLX)
	@echo "\033[1;32m[Done !]" 

all: $(NAME)

clean: 
	@${RM} ${OBJ}
	@echo "\033[0;31m[All .o files were removed]\033[0m"

fclean: clean
	@$(MAKE) fclean -C ./libft
	@${RM} ${SAVE} 
	@echo "\033[0;31m[$(SAVE) was removed]\033[0m"
	@${RM} ${NAME}
	@echo "\033[1;31m[$(NAME) was removed]\033[0m"

re: fclean all

.PHONY: all clean fclean re

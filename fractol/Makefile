# Executable name
NAME := fractol

# Library directories (declared first so they can be used below)
LIBFT_DIR := libft
MLX_DIR := minilibx-linux

# Compiler and flags
CC := cc
CFLAGS := -Wall -Wextra -Werror -I. -I$(LIBFT_DIR) -I$(MLX_DIR)

# Source files
SRC := test01.c test02.c test03.c
OBJ := $(SRC:%.c=%.o)

# Library files
LIBFT := $(LIBFT_DIR)/libft.a
MLX := $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS := -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz

# Default rule: compile fractol
all: $(LIBFT) $(MLX) $(NAME)

# Build executable
$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

# Build libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Build MiniLibX
$(MLX):
	make -C $(MLX_DIR)

# Compile .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

# Full clean (removes binary and libraries)
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(MLX_DIR) clean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re $(LIBFT) $(MLX)

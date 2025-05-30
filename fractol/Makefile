# Name of the final executable
NAME := fractol

# Directory containing libft (42's C utility library)
LIBFT_DIR := libft

# Directory containing MiniLibX (graphics library)
MLX_DIR := minilibx-linux

# Compiler to use
CC := cc

# Compiler flags:
#   -Wall -Wextra -Werror : enable all warnings and treat them as errors
#   -I.                   : add current directory to header search path
#   -I$(LIBFT_DIR)        : add libft include directory
#   -I$(MLX_DIR)          : add MiniLibX include directory
CFLAGS := -Wall -Wextra -Werror -I. -I$(LIBFT_DIR) -I$(MLX_DIR)

# Project source files
SRC := main.c args.c event_handling.c mapping_and_init.c rendering.c \

# Object files, automatically generated from SRC
OBJ := $(SRC:%.c=%.o)

# Path to the compiled libft library
LIBFT := $(LIBFT_DIR)/libft.a

# Path to the compiled MiniLibX library
MLX := $(MLX_DIR)/libmlx_Linux.a

# Linker flags for MLX and other libraries:
#   -L$(MLX_DIR)    add MiniLibX directory to the library search path
#   -lmlx_Linux     link the MiniLibX library
#   -lXext          link the X11 Extension library
#   -lX11           link the core X11 library
#   -lm             link the math library (libm)
#   -lz             link the compression library (zlib)
MLX_FLAGS := -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz

# Default rule that builds the project and its dependencies:
# build libft, MLX, then link the executable
all: $(LIBFT) $(MLX) $(NAME)

# Links the final executable from object files and libraries
# This rule avoids relinking if object files haven't changed
$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

# Builds the libft library using its Makefile
$(LIBFT):
	make -C $(LIBFT_DIR)

# Builds the MiniLibX library using its Makefile
$(MLX):
	make -C $(MLX_DIR)

# Compiles .c source files into .o object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Removes the executable and calls clean in submodules
clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

# Removes all generated files including the executable
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(MLX_DIR) clean

# Rebuilds the entire project from scratch
re: fclean all

# Declare phony targets to avoid conflicts with files of the same name
.PHONY: all clean fclean re $(LIBFT) $(MLX)

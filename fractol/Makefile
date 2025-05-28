# Makefile for the fractol project

# Executable name
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

# Source files for your project
SRC := main.c args.c event_handling.c mapping_and_init.c rendering.c \

# Object files, automatically generated from SRC
OBJ := $(SRC:%.c=%.o)

# Static library target for libft
LIBFT := $(LIBFT_DIR)/libft.a

# Static library target for MiniLibX
MLX := $(MLX_DIR)/libmlx_Linux.a

# Linker flags for MLX and other libraries:
#   -L$(MLX_DIR)    add MiniLibX directory to the library search path
#   -lmlx_Linux     link the MiniLibX library
#   -lXext          link the X11 Extension library
#   -lX11           link the core X11 library
#   -lm             link the math library (libm)
#   -lz             link the compression library (zlib)
MLX_FLAGS := -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz

# Default rule: build libft, MLX, then link the executable
all: $(LIBFT) $(MLX) $(NAME)

# Link the executable:
#   $(OBJ)      : project object files
#   $(LIBFT)    : libft static library
#   $(MLX_FLAGS): MLX and other linker flags
#   -o $(NAME)  : output binary name
$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

# Build libft library by invoking its own Makefile
$(LIBFT):
	make -C $(LIBFT_DIR)

# Build MiniLibX library by invoking its own Makefile
$(MLX):
	make -C $(MLX_DIR)

# Pattern rule: compile .c into .o
#   $< : source file
#   $@ : object file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Remove object files
clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

# Full clean: remove binary and run fclean/clean of sublibraries
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(MLX_DIR) clean

# Rebuild everything from scratch
re: fclean all

# Declare phony targets to avoid conflicts with files of the same name
.PHONY: all clean fclean re $(LIBFT) $(MLX)

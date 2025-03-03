################################################ MANDATORY ###

############ VARS ############

# Directories
SRC_DIR      = _mandatory/src
BUILD_DIR    = _mandatory/build
HELPER_DIR   = $(SRC_DIR)/helpers
INCLUDE_DIR  = _mandatory/include
MLX          = minilibx_macos
LIBFT_DIR    = _mandatory/src/libft
LIBGNL_DIR   = _mandatory/src/get_next_line

# Files
NAME         = fdf
LIBFT        = $(LIBFT_DIR)/libft.a
LIBGNL       = $(LIBGNL_DIR)/libgnl.a
DEPS         = $(INCLUDE_DIR)/fdf.h #$(LIBFT_DIR)/libft.h $(LIBGNL_DIR)/get_next_line.h
SRC          = $(SRC_DIR)/main.c \
               $(HELPER_DIR)/input_handling.c
OBJ          = $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Compiler settings
CC           = cc
CFLAGS       = -Wall -Wextra -Werror

# MLX arguments (adjust to OS)
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
    MLX_ARGS = -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit

else ifeq ($(UNAME_S),Linux) #todo
    MLX_ARGS = -Lminilibx_linux -lmlx -lXext -lX11 -lm

endif

############ RULES ############

all: $(NAME)

# making libft.a
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# making libgnl.a
# gnl:
# 	cd $(LIBGNL_DIR) && make
#$(MAKE) -C $(LIBGNL_DIR)

##### Linking
$(NAME): $(OBJ) gnl $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_ARGS) $(LIBGNL) $(LIBFT) -o $(NAME)
	echo "$(GREEN)MANDATORY MADE$(RESET)"

##### Compiling
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

##### Cleaning
clean: libclean
	rm -rf $(BUILD_DIR)

fclean: clean libfclean
	rm -f $(NAME)

re: fclean $(LIBFT) $(LIBGNL) all

libclean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(LIBGNL_DIR)

libfclean:
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(LIBGNL_DIR)

################################################ BONUS ###


# BONUS = checker

# DEPS_BONUS = #*./bonus/include/push_swap_bonus.h ./bonus/include/get_next_line_bonus.h

# SRC_BONUS = #*bonus/src/main_bonus.c \

# OBJ_BONUS = $(SRC_BONUS:bonus/src/%.c=bonus/build/%.o)

# bonus: $(BONUS)

# $(BONUS): $(OBJ_BONUS)
# 	@$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(BONUS)
# 	@echo "\033[32;1;2mBONUS MADE\033[0m"

# bonus/build/%.o: bonus/src/%.c $(DEPS_BONUS)
# 	@mkdir -p $(dir $@)
# 	@$(CC) $(CFLAGS) -c $< -o $@

# bonus_clean:
# 	@rm -rf bonus/build
	
# bonus_fclean: bonus_clean
# 	@rm -f $(BONUS)

# bonus_re: bonus_fclean bonus

######################## .PHONY ###########################

.PHONY: clean bonus_clean

######################## COLORs ###########################

# GREEN = \033[0;32m
# RED = \033[0;31m
# RESET = \033[0m
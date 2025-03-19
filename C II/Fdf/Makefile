################################################ MANDATORY #############################################

################################################
#                 DIRECTORIES                  #
################################################

SRC_DIR      = _mandatory/src
BUILD_DIR    = _mandatory/build
HELPER_DIR   = $(SRC_DIR)/helpers
INCLUDE_DIR  = _mandatory/include
MLX_DIR = MLX
################################################
#                  FILES                       #
################################################

NAME         = fdf
FDFDEPS      = $(INCLUDE_DIR)/fdf.h
FDFSRC       = $(SRC_DIR)/main.c \
				$(HELPER_DIR)/input_handling.c \
				$(HELPER_DIR)/input_parsing.c \
				$(HELPER_DIR)/ft_free.c \
				$(HELPER_DIR)/utils.c \
				$(HELPER_DIR)/ft_errors.c \
				$(HELPER_DIR)/bresenham.c \
				$(HELPER_DIR)/key_hooks.c \
				$(HELPER_DIR)/draw.c \
				$(HELPER_DIR)/color.c \
				$(HELPER_DIR)/project.c \

FDFOBJ       = $(FDFSRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

################################################
#             COMPILER SETTINGS                #
################################################

CFLAGS       = -Wall -Wextra -Werror -Ofast #-fsanitize=address -Wunreachable-code

################################################
#              OS DETECTION                    #
################################################

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	MLX_FLAGS = -LMLX/build -lmlx42 -lglfw3 -IMLX/include -framework Cocoa -framework OpenGL -framework IOKit
	CC        = cc
	os_msg = "$(GREEN)OS DETECTED Mac!$(RESET)"

else ifeq ($(UNAME_S),Linux)
	MLX_FLAGS = -LMLX_Linux/build/ -lmlx42 -lglfw -lGL -lm -ldl -lpthread -lX11 -I MLX_Linux/include
	CC		  = cc
	os_msg = "$(GREEN)OS DETECTED Linux!$(RESET)"
endif

################################################
#                   RULES                      #
################################################

all: $(BUILD_DIR) MLX_BIN $(NAME)

MLX_BIN:
	if [ ! -d "MLX" ]; then \
		git clone https://github.com/MrY2K/MLX.git; \
	fi

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
	echo "$(GREEN)making the build dir$(RESET)"

# making libft.a
LIBFT_DIR    = _mandatory/src/libft
LIBFT        = $(LIBFT_DIR)/libft.a
LIBFT_HDR = $(LIBFT_DIR)/libft.h
LIBFT_SRC = $(LIBFT_DIR)/ft_split.c
$(LIBFT): $(LIBFT_SRC) $(LIBFT_HDR)
	$(MAKE) -C $(LIBFT_DIR)
	echo "$(GREEN)Compiled $(LIBFT)$(RESET)"

# making libgnl.a
LIBGNL_DIR   = _mandatory/src/get_next_line
LIBGNL       = $(LIBGNL_DIR)/libgnl.a
GNL_HDR      = $(LIBGNL_DIR)/get_next_line.h
GNL_SRC      = $(LIBGNL_DIR)/get_next_line.c $(LIBGNL_DIR)/get_next_line_utils.c
$(LIBGNL): $(GNL_SRC) $(GNL_HDR)
	$(MAKE) -C $(LIBGNL_DIR)
	echo "$(GREEN)Compiled $(LIBGNL)$(RESET)"

##### Linking
$(NAME): $(FDFOBJ) $(LIBGNL) $(LIBFT)
	$(CC) $(CFLAGS) $(FDFOBJ) $(MLX_FLAGS) $(LIBGNL) $(LIBFT) -o $(NAME) 
	echo "$(GREEN)MADE $(NAME) $(RESET)"

##### Compiling into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(FDFDEPS) 
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -IMLX/include -I$(INCLUDE_DIR) -I$(LIBGNL_DIR) -I$(LIBFT_DIR) -c $< -o $@

################################################ BONUS ################################################

################################################
#                 DIRECTORIES                  #
################################################

SRC_DIR_BONUS      = _bonus/src
BUILD_DIR_BONUS    = _bonus/build
HELPER_DIR_BONUS   = $(SRC_DIR_BONUS)/helpers
INCLUDE_DIR_BONUS  = _bonus/include

################################################
#                  FILES                       #
################################################

BONUS = fdf_bonus
FDFDEPS_BONUS = $(INCLUDE_DIR_BONUS)/fdf_bonus.h
FDFSRC_BONUS  = $(SRC_DIR_BONUS)/main_bonus.c \
				$(HELPER_DIR_BONUS)/input_handling_bonus.c \
				$(HELPER_DIR_BONUS)/input_parsing_bonus.c \
				$(HELPER_DIR_BONUS)/ft_free_bonus.c \
				$(HELPER_DIR_BONUS)/utils_bonus.c \
				$(HELPER_DIR_BONUS)/ft_errors_bonus.c \
				$(HELPER_DIR_BONUS)/bresenham_bonus.c \
				$(HELPER_DIR_BONUS)/key_hooks_bonus.c \
				$(HELPER_DIR_BONUS)/draw_bonus.c \
				$(HELPER_DIR_BONUS)/color_bonus.c \
				$(HELPER_DIR_BONUS)/project_bonus.c \
				$(HELPER_DIR_BONUS)/init_bonus.c \

FDFOBJ_BONUS = $(FDFSRC_BONUS:$(SRC_DIR_BONUS)/%.c=$(BUILD_DIR_BONUS)/%.o)

bonus: $(BUILD_DIR_BONUS) $(BONUS)

$(BUILD_DIR_BONUS):
	mkdir -p $(BUILD_DIR_BONUS)
	echo "$(GREEN)making the build dirfor the bonus$(RESET)"

# making libft.a
LIBFT_DIR_BONUS    = _bonus/src/libft
LIBFT_BONUS        = $(LIBFT_DIR_BONUS)/libft.a
LIBFT_HDR_BONUS = $(LIBFT_DIR_BONUS)/libft_bonus.h
LIBFT_SRC_BONUS = $(LIBFT_DIR_BONUS)/ft_split_bonus.c
$(LIBFT_BONUS): $(LIBFT_SRC_BONUS) $(LIBFT_HDR_BONUS)
	$(MAKE) -C $(LIBFT_DIR_BONUS)
	echo "$(GREEN)Compiled $(LIBFT_BONUS)$(RESET)"

# making libgnl.a
LIBGNL_DIR_BONUS   = _bonus/src/get_next_line
LIBGNL_BONUS       = $(LIBGNL_DIR_BONUS)/libgnl.a
GNL_HDR_BONUS      = $(LIBGNL_DIR_BONUS)/get_next_line_bonus.h
GNL_SRC_BONUS      = $(LIBGNL_DIR_BONUS)/get_next_line_bonus.c $(LIBGNL_DIR_BONUS)/get_next_line_utils_bonus.c
$(LIBGNL_BONUS): $(GNL_SRC_BONUS) $(GNL_HDR_BONUS)
	$(MAKE) -C $(LIBGNL_DIR_BONUS)
	echo "$(GREEN)Compiled $(LIBGNL_BONUS)$(RESET)"

##### Linking
$(BONUS): $(FDFOBJ_BONUS) $(LIBGNL_BONUS) $(LIBFT_BONUS)
	$(CC) $(CFLAGS) $(FDFOBJ_BONUS) $(MLX_FLAGS) $(LIBGNL_BONUS) $(LIBFT_BONUS) -o $(BONUS) 
	echo "$(GREEN)MADE $(BONUS) $(RESET)"

_bonus/build/%.o: _bonus/src/%.c $(FDFDEPS_BONUS)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -IMLX/include -I$(INCLUDE_DIR) -I$(LIBGNL_DIR_BONUS) -I$(LIBFT_DIR_BONUS) -c $< -o $@

bonus_clean:
	rm -rf _bonus/build
	echo "$(RED)bonus cleaning done! $(RESET)"
	
bonus_fclean: bonus_clean
	rm -f $(BONUS)

bonus_re: bonus_fclean bonus

##### Cleaning 
clean: libclean
	rm -rf $(BUILD_DIR)
	echo "$(RED)cleaning done! $(RESET)"

fclean: clean libfclean 
	rm -f $(NAME)

re: fclean $(LIBGNL) $(LIBFT) all

re_bonus: bonus_fclean $(LIBGNL_BONUS) $(LIBFT_BONUS) bonus

libclean:
	$(MAKE) clean -C $(LIBFT_DIR)
	echo "$(RED)Cleaned $(LIBFT_DIR)$(RESET)"
	$(MAKE) clean -C $(LIBGNL_DIR)
	echo "$(RED)Cleaned $(LIBGNL_DIR)$(RESET)"

libfclean:
	$(MAKE) fclean -C $(LIBFT_DIR)
	echo "$(RED)Full Cleaned $(LIBFT_DIR)$(RESET)"
	$(MAKE) fclean -C $(LIBGNL_DIR)
	echo "$(RED)Full Cleaned $(LIBGNL_DIR)$(RESET)"

libclean_bonus:
	$(MAKE) clean -C $(LIBFT_DIR_BONUS)
	echo "$(RED)Cleaned $(LIBFT_DIR_BONUS)$(RESET)"
	$(MAKE) clean -C $(LIBGNL_DIR)
	echo "$(RED)Cleaned $(LIBGNL_DIR_BONUS)$(RESET)"

libfclean_bonus:
	$(MAKE) fclean -C $(LIBFT_DIR_BONUS)
	echo "$(RED)Full Cleaned $(LIBFT_DIR_BONUS)$(RESET)"
	$(MAKE) fclean -C $(LIBGNL_DIR_BONUS)
	echo "$(RED)Full Cleaned $(LIBGNL_DIR_BONUS)$(RESET)"

maps:
	git clone https://github.com/MrY2K/Eval-Tests.git

######################## .PHONY ###########################

.PHONY: clean bonus_clean MLX_BIN maps libclean libfclean libclean_bonus libfclean_bonus

######################## COLORs ###########################

GREEN = \033[0;32m
RED   = \033[0;31m
RESET = \033[0m
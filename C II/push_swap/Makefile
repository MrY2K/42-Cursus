CC = cc
CFLAGS = -Wall -Wextra -Werror -I./mandatory/include/ -I./bonus/include/

########################## MANDATORY #############################

NAME = push_swap

DEPS = ./mandatory/include/push_swap.h

SRC = mandatory/src/main.c \
	mandatory/src/libft/ft_list_manipulation.c \
	mandatory/src/libft/ft_list_manipulation2.c \
	mandatory/src/libft/ft_string_manipulation.c \
	mandatory/src/libft/ft_string_manipulation_2.c \
	mandatory/src/libft/ft_atoi.c \
	mandatory/src/libft/ft_split.c \
	mandatory/src/helpers/ft_validate_input.c \
	mandatory/src/helpers/ft_validate_input2.c \
	mandatory/src/helpers/fill_the_stack.c \
	mandatory/src/helpers/ft_free.c \
	mandatory/src/helpers/ft_error.c \
	mandatory/src/helpers/sorting.c \
	mandatory/src/helpers/sorting2.c \
	mandatory/src/helpers/sorting3.c \
	mandatory/src/ops/ops1.c \
	mandatory/src/ops/ops2.c \
	mandatory/src/ops/ops3.c

OBJ = $(SRC:mandatory/src/%.c=mandatory/build/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[32;1;1mMANDATORY MADE\033[0m"

mandatory/build/%.o: mandatory/src/%.c $(DEPS)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	@rm -rf mandatory/build
	
fclean: clean
	@rm -f $(NAME)

re: fclean all

######################## BONUS ############################

BONUS = checker

DEPS_BONUS = ./bonus/include/push_swap_bonus.h ./bonus/include/get_next_line_bonus.h

SRC_BONUS = bonus/src/main_bonus.c \
	bonus/src/helpers/ft_error_bonus.c \
	bonus/src/helpers/ft_free_bonus.c \
	bonus/src/helpers/fill_the_stack_bonus.c \
	bonus/src/helpers/ft_list_manipulation_bonus.c \
	bonus/src/helpers/ft_list_manipulation2_bonus.c \
	bonus/src/helpers/ft_string_manipulation_bonus.c \
	bonus/src/helpers/ft_string_manipulation_2_bonus.c \
	bonus/src/helpers/ft_validate_input_bonus.c \
	bonus/src/helpers/ft_validate_input2_bonus.c \
	bonus/src/helpers/sorting2_bonus.c \
	bonus/src/helpers/ft_split_bonus.c \
	bonus/src/helpers/ft_atoi_bonus.c \
	bonus/src/ops_bonus/ops1_bonus.c \
	bonus/src/ops_bonus/ops2_bonus.c \
	bonus/src/ops_bonus/ops3_bonus.c \
	bonus/src/gnl/get_next_line_bonus.c \
	bonus/src/gnl/get_next_line_utils_bonus.c

OBJ_BONUS = $(SRC_BONUS:bonus/src/%.c=bonus/build/%.o)

bonus: $(BONUS)

$(BONUS): $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(BONUS)
	@echo "\033[32;1;2mBONUS MADE\033[0m"

bonus/build/%.o: bonus/src/%.c $(DEPS_BONUS)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

bonus_clean:
	@rm -rf bonus/build
	
bonus_fclean: bonus_clean
	@rm -f $(BONUS)

bonus_re: bonus_fclean bonus

######################## .PHONY ###########################

.PHONY: clean bonus_clean
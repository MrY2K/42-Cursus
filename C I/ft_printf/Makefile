CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
DEPS = ft_printf.h
SRC = ft_printf.c ft_putadd.c ft_putchar.c ft_putnbr_hex.c ft_putnbr_unsigned.c ft_putnbr.c ft_putstr.c
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
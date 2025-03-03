NAME = libgnl.a
CFLAGS = -Wall -Wextra -Werror
CC = cc
SRC = get_next_line.c get_next_line_utils.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(OBJB)

fclean: clean
	rm -f $(NAME) $(OBJ) $(OBJB)

re: fclean all

.PHONY: clean
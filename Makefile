SRC = get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)
GCC_FLAGS = -Wall -Wextra -Werror
CC = gcc
HEADER = get_next_line.h
AR = ar r
NAME = get_next_line.a

all: $(NAME)

$(NAME) :$(OBJ)
		$(AR) $(NAME) $(OBJ)
%.o: %.c
		$(CC) $(GCC_FLAGS) -c $<
clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ) $(NAME)
re: fclean all
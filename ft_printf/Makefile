NAME = libftprintf.a

CC = cc

CCFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
      ft_printchars.c \
      ft_printnbr.c \
      ft_printpointer.c \
      ft_printhex.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


FLAGS = -Wall -Werror -Wextra

INC = ./ft_printf.h

SRC = ft_printf.c tools.c main.c

TEST = test_suite

LIBFT = ../libft/

all: $(LIBFT)
	gcc -o $(TEST) $(SRC) -L. -lft

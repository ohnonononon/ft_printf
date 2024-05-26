
FLAGS = -Wall -Werror -Wextra

INC = ./ft_printf.h

SRC = ft_printf.c tools.c

TEST = test_suite

all:
	gcc $(SRC) -L $(INC) -o $(TEST) 

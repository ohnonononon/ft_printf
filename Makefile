
FLAGS = -Wall -Werror -Wextra

INC = ./ft_printf.h

SRC = ft_printf.c tools.c main.c

TEST = test_suite

all:
	gcc -L $(INC) $(SRC) -o $(TEST) 

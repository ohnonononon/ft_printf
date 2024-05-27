FLAGS = -Wall -Werror -Wextra

INC = ./ft_printf.h

SRC = ft_printf.c tools.c main.c convert.c

TEST = test_suite

all: $(LIBFT)
	gcc -o $(TEST) $(SRC) -L. -lft

db:
	gcc -o $(TEST) $(SRC) -L. -lft -g
	dbg ./$(TEST)

clean:
	rm $(TEST)

re: clean all

.PHONY: re clean db all

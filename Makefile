FLAGS = -Wall -Werror -Wextra

INC = ./ft_printf.h

SRC = ft_printf.c tools.c main.c convert.c

TEST = test_suite

all: $(LIBFT)
	gcc -o $(TEST) $(SRC) -L. -lft

debug:
	gcc -o $(TEST) $(SRC) -L. -lft -g

clean:
	rm $(TEST)

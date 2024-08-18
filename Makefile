# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohnudes <nimatura@student.42barcel>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/17 17:10:54 by ohnudes           #+#    #+#              #
#    Updated: 2024/08/18 17:08:30 by nimatura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre del programa
NAME = libftprintf.a

# Flags al compilar
FLAGS = -Wall -Wextra -Werror

# Flags for linking
LNK = ar rcs

# Include
INC = ft_printf.h

# Functions
SRC = ft_printf.c printf_tools.c printf_convert.c

# Objects
OBJ = $(SRC:.c=.o)

#### LIBFT
LFT_DIR = libft/
LIBFT = libft.a
LFT	= $(addprefix $(LFT_DIR), $(LIBFT))

#### Compilacion del programa ####

all: libs $(NAME)

$(NAME): $(OBJ)
	@echo Creating library: $(NAME)...
	@cp $(LFT_DIR)$(LIBFT) $(NAME)
	$(LNK) $@ $(OBJ)
	@echo Library completed.

libs:
	make -C $(LFT_DIR)

%.o: %.c Makefile $(INC)
	@echo Compiling $<...
	gcc -c $(FLAGS) $< -o $@
	@echo Compilation completed.

fclean: clean
	@rm -f $(NAME)

clean:
	make -C $(LFT_DIR) fclean
	rm -f libs
	rm -f $(OBJ)

re: fclean all

.PHONY: all clean fclean re

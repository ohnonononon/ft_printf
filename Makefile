# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 14:08:04 by nmaturan          #+#    #+#              #
#    Updated: 2024/08/07 18:49:25 by nimatura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre del programa
NAME = libftprintf.a

# Flags al compilar
FLAGS = -g -Wall -Wextra -Werror

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

# Deps 
DEPS = $(addprefix $(LFT_DIR), $(LIBFT)) 

#### Compilacion del programa ####

all: $(NAME) makecheck

$(NAME): $(OBJ) $(DEPS)
	@echo Creating library: $(NAME)...
	@cp $(LFT_DIR)$(LIBFT) $(NAME)
	$(LNK) $@ $(OBJ)
	@echo Library completed.

$(DEPS):
	@make -C $(LFT_DIR)

%.o: %.c
	@echo Compiling $<...
	@gcc -c $(FLAGS) $< -o $@  
	@echo Compilation completed.

makecheck:
	@make -C $(LFT_DIR)
	@make -C . $(NAME)

fclean: clean
	@rm -f $(NAME)

clean:
	@make -C $(LFT_DIR) fclean
	@rm -f $(OBJ)

re: fclean all

.PHONY: all clean fclean re makecheck

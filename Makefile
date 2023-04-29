# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 13:05:48 by gpouzet           #+#    #+#              #
#    Updated: 2023/04/29 20:26:07 by gpouzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 	= clang

FLAGS = -Wall -Wextra -Werror -g

NAME = so_long

NAMEB = so_long_bonus

SRC = source/main.c source/map.c source/parser.c source/tools.c \

BNS = 

OBJ	= $(SRC:.c=.o)

OBJB = $(BNS:.c=.o)

%.o: %.c
	@$(CC) $(FLAGS) -o $@ -c $<
	@echo -n "\\r\033[2K"
	@echo -n "\\r\033[1;33m[compiling...]"$<

all: $(NAME)

bonus: $(NAMEB)

$(NAME): $(OBJ)
	@make -s --no-print-directory -C minilibx
	@make -s --no-print-directory -C libft
	@$(CC) $(FLAGS) $(OBJ) -L./libft -lft -L./minilibx -lmlx_Linux -lXext -lX11 -o $(NAME) 
	@echo -n "\\r\033[2K"
	@echo "\033[1;32m[executable created]"

$(NAMEB): $(OBJB)
	@make -s --no-print-directory -C libft
	@$(CC) $(FLAGS) $(OBJB) -L./libft -lft -o $(NAMEB)
	@echo -n "\\r\033[2K"
	@echo "\033[1;32m[executable created]"

clean:
	@make fclean --no-print-directory -C libft
	@make clean -s -C minilibx
	@rm -rf $(OBJ) $(OBJB)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(NAMEB)
	@echo "\033[1;32m[Programe deleted]"

re: fclean all

.PHONY: all clean fclean re bonus

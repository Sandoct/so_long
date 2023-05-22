# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 13:05:48 by gpouzet           #+#    #+#              #
#    Updated: 2023/05/20 19:46:35 by gpouzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 	= clang

FLAGS = -Wall -Wextra -Werror -g

NAME = so_long

NAMEB = so_long_bonus

SRC = src/main.c src/map.c src/parser.c src/so_long.c \
	  src/tools.c src/event.c src/setup.c src/render.c \

BNS = src_bonus/main_bonus.c src_bonus/map.c src_bonus/parser.c src_bonus/so_long_bonus.c \
	  src_bonus/tools.c src_bonus/event.c src_bonus/setup.c src_bonus/render.c src_bonus/loop.c \

OBJ	= $(SRC:.c=.o)

OBJB = $(BNS:.c=.o)

%.o: %.c
	@$(CC) $(FLAGS) -o $@ -c $<
	@echo -n "\\r\033[2K"
	@echo -n "\\r\033[1;33m[compiling...]"$<

all: $(NAME)

bonus: $(NAMEB)

$(NAME): $(OBJ)
	@make -s --no-print-directory -C libft
	@make -s --no-print-directory -C minilibx
	@$(CC) $(FLAGS) $(OBJ) -L./libft -lft -L./minilibx -lmlx_Linux -lXext -lX11 -o $(NAME) 
	@echo -n "\\r\033[2K"
	@echo "\033[1;32m[executable created]"

$(NAMEB): $(OBJB)
	@make -s --no-print-directory -C libft
	@make -s --no-print-directory -C minilibx
	@$(CC) $(FLAGS) $(OBJB) -L./libft -lft -L./minilibx -lmlx_Linux -lXext -lX11 -o $(NAMEB) 
	@echo -n "\\r\033[2K"
	@echo "\033[1;32m[executable bonus created]"

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

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/14 22:43:59 by jpinyot           #+#    #+#              #
#    Updated: 2017/12/14 23:27:49 by jpinyot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

FLAGS = -Wall -Wextra -Werror

SRC = srcs/*.c

OBJ = ./*.o

all: $(NAME)

$(NAME):
	@$(MAKE) -C libft
	@gcc $(FLAGS) -c -I./includes -I./libft $(SRC)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -L./libft -lft

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean
	make

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/14 22:43:59 by jpinyot           #+#    #+#              #
#    Updated: 2018/01/28 15:53:21 by jpinyot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

FLAGS = 

SRC = srcs/ft_printf.c\
	  srcs/ft_printf_check_flags.c\
	  srcs/funct/ft_printf_new_arg.c\
	  srcs/conversions/conv_int.c\
	  srcs/conversions/conv_unsigned_int.c\
	  srcs/conversions/conv_char.c\
	  srcs/conversions/conv_str.c\
	  srcs/conversions/conv_utf_8.c\
	  srcs/conversions/conv_str_utf_8.c\
	  srcs/funct/ft_printf_putint.c\
	  srcs/funct/ft_printf_putuint.c\
	  srcs/funct/ft_printf_putchar.c\
	  srcs/funct/ft_printf_putstr.c\
	  srcs/funct/ft_printf_pututf_8.c\
	  srcs/funct/ft_printf_putstr_utf_8.c\
	  srcs/funct/ft_printf_itoa.c\
	  srcs/funct/ft_printf_itoa_hex.c\
	  srcs/funct/ft_printf_itoa_oct.c\
	  srcs/funct/ft_printf_from_int_to_utf_8.c\
	  srcs/funct/ft_printf_funct.c\
	  srcs/main.c

OBJ = ft_printf.o\
	  ft_printf_check_flags.o\
	  ft_printf_new_arg.o\
	  conv_int.o\
	  conv_unsigned_int.o\
	  conv_char.o\
	  conv_str.o\
	  conv_utf_8.o\
	  conv_str_utf_8.o\
	  ft_printf_putint.o\
	  ft_printf_putuint.o\
	  ft_printf_putchar.o\
	  ft_printf_putstr.o\
	  ft_printf_pututf_8.o\
	  ft_printf_putstr_utf_8.o\
	  ft_printf_itoa.o\
	  ft_printf_itoa_hex.o\
	  ft_printf_itoa_oct.o\
	  ft_printf_from_int_to_utf_8.o\
	  ft_printf_funct.o\
	  main.o

all: $(NAME)

$(NAME):
	@$(MAKE) -C libft
	@gcc $(FLAGS) -c -I./includes -I./libft $(SRC)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -L./libft -lft
	@printf '\033[32m[ ✔ ] %s\n\033[0m' "Correct compilation!"

clean:
	@/bin/rm -f $(OBJ)
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean"

fclean: clean
	@/bin/rm -f $(NAME)
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean"

re: fclean
	make

.PHONY: all clean fclean re

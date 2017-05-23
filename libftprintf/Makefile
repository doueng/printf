# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: douglas <douglas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/20 09:25:40 by dengstra          #+#    #+#              #
#    Updated: 2017/05/23 15:15:01 by dengstra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = ft_printf.h libft/libft.h
FLAGS = -Wextra -Wall -Werror
LIBFT = ./libft

SRC = get_flags.c ft_printf.c printer.c convert.c is_id.c padding.c putwstr.c input_checker.c
SRCO = ${SRC:%.c=%.o}

all: $(NAME)

$(NAME):
	@make -C $(LIBFT)
	gcc $(FLAGS) $(SRC) -I$(HEADER) -c
	@ar rc $(NAME) $(SRCO) ./libft/*.o
	@ranlib $(NAME)

clean:
	/bin/rm -f $(SRCO)
	@make clean -C $(LIBFT)

fclean: clean
	/bin/rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: clean fclean re all

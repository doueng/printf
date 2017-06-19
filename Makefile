# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/20 09:25:40 by dengstra          #+#    #+#              #
#    Updated: 2017/06/07 12:19:28 by dengstra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wextra -Wall -Werror
LIBFT = ./libft

SRC =	bytes.c				\
		ft_printf.c			\
		padding.c			\
		get_flags.c			\
		input_checker.c		\
		is_id.c				\
		length_converter.c	\
		printer.c			\
		printnbr.c			\
		printstr.c			\
		putwstr.c

LIBSRCO = libft/ft_putstrfree.o	\
			libft/ft_only_char.o	\
			libft/ft_strndup.o	\
			libft/ft_isdigit.o	\
			libft/ft_strcat.o		\
			libft/ft_strdup.o		\
			libft/ft_memalloc.o	\
			libft/ft_memset.o		\
			libft/ft_memmove.o	\
			libft/ft_strnew.o		\
			libft/ft_strjoin.o	\
			libft/ft_itoa.o		\
			libft/ft_itoa_base.o	\
			libft/ft_strchr.o	\
			libft/ft_putchar.o	\
			libft/ft_atoi.o		\
			libft/ft_bzero.o		\
			libft/ft_putstr.o		\
			libft/ft_strlen.o

SRCO = ${SRC:%.c=%.o}

all: $(NAME)

$(NAME):
	@make -C $(LIBFT)
	gcc $(FLAGS) $(SRC) -c
	@ar rc $(NAME) $(SRCO) $(LIBSRCO)

clean:
	/bin/rm -f $(SRCO)
	@make clean -C $(LIBFT)

fclean: clean
	/bin/rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: clean fclean re all

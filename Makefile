# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdel-agu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 09:36:05 by rdel-agu          #+#    #+#              #
#    Updated: 2021/12/06 21:42:13 by rdel-agu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
RM = rm
OBJ = $(SRC:.c=.o)
CFGLAGS = -Wall -Wextra -Werror
SRC =		ft_printf.c\
		ft_printf_hex.c\
		ft_printf_point.c\
		ft_printf_charstr.c\
		ft_printf_nbrs.c\

all: $(NAME)

%.o: %.c
	$(CC) -o $@ -c $<

$(NAME): $(OBJ)
	ar rcs $@ $(OBJ)

clean:
	$(RM) -f $(OBJ)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

norme:
	norminette -R CheckForbiddenSourceHeader $(SRC)

.PHONY: clean fclean

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdornic <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 21:58:09 by gdornic           #+#    #+#              #
#    Updated: 2023/09/25 15:19:36 by gdornic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

DEP = ../libft

HEADERS = -I../libft

LIB_LINK = -L../libft -lft

SRC = ft_balloc.c ft_itoa_base.c ft_printf.c ft_printf_utils.c ft_chrswap.c ft_itoa_base_pointer.c inclusive_strjoin.c ft_chrtostr.c ft_memset_int.c ft_printf_utils2.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

define make_dep
	for d in $(DEP) ; do \
		make -C $$d $(1) ; \
	done
endef

all: $(NAME)

$(NAME): $(OBJ)
	$(call make_dep,all)
	ar -cr $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(call make_dep,clean)

fclean: clean
	rm -f $(NAME)
	$(call make_dep,fclean)

re: fclean all

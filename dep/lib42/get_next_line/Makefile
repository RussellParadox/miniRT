# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 21:58:09 by gdornic           #+#    #+#              #
#    Updated: 2024/01/03 14:57:39 by gdornic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

DEP =

HEADERS =

LIB_LINK =

SRC = get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

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

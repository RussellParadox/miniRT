# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 21:58:09 by gdornic           #+#    #+#              #
#    Updated: 2024/01/01 16:16:52 by gdornic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

DEP = $(addprefix dep/, lib42 mlx_linux)

HEADERS = $(addprefix -I, $(DEP)) -I/usr/include -Isrc

LIB_LINK = $(addprefix -L, $(DEP)) -lmlx_Linux -l42 -L/usr/lib -lXext -lX11 -lm -lz

SRC = 	$(addprefix view/, ) \
		$(addprefix controller/, \
			$(addprefix hook/, routine.c) \
			$(addprefix image/, pixel_put.c) \
			$(addprefix canva/, pixel_put.c) \
			main.c loop.c routine.c) \
		$(addprefix model/, \
			$(addprefix scene/, \
				$(addprefix vector/, ) \
				$(addprefix color/, ) \
				$(addprefix object/, \
					$(addprefix ambient_lightning/, create.c) \
					$(addprefix camera/, create.c) \
					$(addprefix cylinder/, create.c) \
					$(addprefix light/, create.c) \
					$(addprefix plane/, create.c) \
					$(addprefix sphere/, create.c) \
					next_object.c create.c) \
				create.c) \
			)

OBJ = $(addprefix obj/, $(SRC:.c=.o))

CC = gcc

CFLAGS = -Werror -Wall -Wextra

define make_dep
	for d in $(DEP) ; do \
		make -C $$d $(1) ; \
	done
endef

all: $(NAME)

$(NAME): $(OBJ)
	$(call make_dep,all)
	$(CC) $(OBJ) $(HEADERS) $(LIB_LINK) -o $(NAME)

obj/%.o: src/%.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(call make_dep,clean)

fclean: clean
	rm -f $(NAME)
	$(call make_dep,fclean)

re: fclean all

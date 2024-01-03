# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 21:58:09 by gdornic           #+#    #+#              #
#    Updated: 2024/01/03 23:02:05 by gdornic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

DEP = $(addprefix dep/, lib42 mlx_linux toolbox)

HEADERS = $(addprefix -I, $(DEP)) -I/usr/include -Isrc

LIB_LINK = $(addprefix -L, $(DEP)) -lmlx_Linux -l42 -ltoolbox -L/usr/lib -lXext -lX11 -lm -lz

SRC = 	$(addprefix view/, ) \
		$(addprefix controller/, \
			$(addprefix mlx/, create.c free.c) \
			$(addprefix hook/, routine.c loop_end.c) \
			$(addprefix image/, pixel_put.c) \
			$(addprefix canva/, pixel_put.c) \
			main.c loop.c routine.c) \
		$(addprefix model/, \
			$(addprefix scene/, \
				$(addprefix object/, \
					$(addprefix color/, create.c free.c) \
					$(addprefix vector/, create.c free.c) \
					$(addprefix ambient_lightning/, create.c free.c) \
					$(addprefix camera/, create.c free.c) \
					$(addprefix cylinder/, create.c free.c) \
					$(addprefix light/, create.c free.c) \
					$(addprefix plane/, create.c free.c) \
					$(addprefix sphere/, create.c free.c) \
					next_object.c create.c free.c) \
				create.c free.c) \
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

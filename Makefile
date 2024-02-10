# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 21:58:09 by gdornic           #+#    #+#              #
#    Updated: 2024/02/10 16:43:38 by gdornic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

DEP = $(addprefix dep/, lib42 mlx_linux toolbox)

HEADERS = $(addprefix -I, $(DEP)) -I/usr/include -Isrc

LIB_LINK = $(addprefix -L, $(DEP)) -lmlx_Linux -l42 -ltoolbox -L/usr/lib -lXext -lX11 -lm -lz

SRC = 	$(addprefix view/, routine.c) \
		$(addprefix controller/, \
			$(addprefix renderer/, \
				$(addprefix raytracing/, \
					$(addprefix intersection/, closest.c intersect.c quadratic_minimum.c sphere.c plane.c cylinder.c) \
					$(addprefix light/, \
						$(addprefix intensity/, light_intensity.c ambient_lightning.c light_point.c) \
						effect.c reflection.c) \
					method.c render.c) \
				draw_circle.c) \
			$(addprefix mlx/, create.c free.c) \
			$(addprefix hook/, routine.c loop_end.c) \
			$(addprefix image/, \
				$(addprefix color_trgb/, create.c) \
				create.c pixel_put.c free.c) \
			$(addprefix canva/, pixel_put.c) \
			$(addprefix parsing/, \
				$(addprefix rule/, ambient_lightning.c camera.c cylinder.c light.c plane.c sphere.c rgb.c float.c int.c vector.c vector_normalized.c) \
				argument_fail.c put_error.c) \
			main.c loop.c routine.c) \
		$(addprefix model/, \
			$(addprefix scene/, \
				$(addprefix object/, \
					$(addprefix color/, create.c free.c) \
					$(addprefix vector/, matrix_transpose.c matrix_product.c matrix_inverse.c normalize.c cross_product.c rotation.c sum.c sub.c create.c free.c scalar_product.c norm.c) \
					$(addprefix ambient_lightning/, create.c free.c) \
					$(addprefix camera/, create.c free.c) \
					$(addprefix cylinder/, create.c free.c) \
					$(addprefix light/, create.c free.c) \
					$(addprefix plane/, create.c free.c) \
					$(addprefix sphere/, create.c free.c) \
					$(addprefix method/, \
						$(addprefix normal/, init.c sphere.c plane.c cylinder.c) \
						$(addprefix tangeant/, sphere.c cylinder.c) \
						$(addprefix mapping/, cylinder.c sphere.c plane.c) \
						$(addprefix color/, cylinder.c sphere.c plane.c routine.c) \
						$(addprefix bump/, plane.c sphere.c cylinder.c routine.c) \
						reflective.c ratio.c specular.c find.c) \
					$(addprefix map/, create.c free.c) \
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

obj_tree:
	mkdir -p $(dir $(OBJ))

obj/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	rm -rf obj
	$(call make_dep,clean)

fclean: clean
	rm -f $(NAME)
	$(call make_dep,fclean)

re: fclean all

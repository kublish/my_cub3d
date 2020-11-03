# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zacharykubli <marvin@42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/07 18:56:37 by zacharyku         #+#    #+#              #
#    Updated: 2020/11/02 13:48:23 by zacharyku        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBS = -lmlx libft/libft.a
FLAGS = -fsanitize=address #-Wall -Wextra -Werror
OBJS = main.o launch.o render.o input.o getters.o hooks.o map_reader.o tools.o movement.o
NAME = cub3d

all: $(NAME)

$(NAME): $(OBJS) cub3d.h hooks.h
	cd libft && $(MAKE)
	gcc -g $(LIBS) $(FLAGS) -o $(NAME) $(OBJS)

$(OBJS): %.o : %.c
	gcc -g -c $(FLAGS) $<

clean:
	rm $(OBJS)
	cd libft && $(MAKE) clean

re: clean all

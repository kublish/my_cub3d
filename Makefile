# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zacharykubli <marvin@42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/07 18:56:37 by zacharyku         #+#    #+#              #
#    Updated: 2020/11/25 15:29:25 by zacharyku        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBS = -lmlx libft/libft.a
FLAGS = -fsanitize=address #-Wall -Wextra -Werror
OBJS = main.o launch.o render.o input.o getters.o hooks.o map_reader.o tools.o movement.o
NAME = cub3d

pull:
	clear
	git pull
	make all

push:
	git add .
	git commit -m "test"
	git push

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

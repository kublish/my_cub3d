# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zkubli <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/16 11:27:43 by zkubli            #+#    #+#              #
#    Updated: 2020/03/11 10:27:34 by zkubli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# libft
SRCS = ft_atoi.c ft_bzero.c ft_gcf.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprime.c ft_isprint.c ft_isspace.c ft_itoa.c ft_lcm.c ft_lstadd.c ft_lstcontain.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_pow.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtol.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_remalloc.c ft_strndup.c ft_digitcount.c ft_strappend.c
# linked lists
SRCS += ft_lstadd.c ft_lstcontain.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_lstappend.c ft_lstprepend.c ft_lstsort.c ft_lstfrontpop.c ft_lstpop.c
# printf
SRCS += ft_printf.c get_format.c helper.c printer.c ft_printf_c.c ft_printf_s.c ft_printf_d.c ft_printf_u.c ft_printf_x.c ft_printf_o.c ft_printf_p.c ft_printf_f.c ft_printf_b.c string_math.c ft_printf_b.c
# vectors
SRCS += ft_vnew.c ft_vdoublecap.c ft_vget.c ft_vadd.c ft_vdel.c ft_vinsert.c ft_vswap.c ft_vsort.c ft_vdestroy.c
# priority queue
SRCS += ft_pqueue.c
OBJS = $(SRCS:.c=.o)
HDRS = libft.h
LIBS = ./ft_printf/libftprintf.a
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: srcs/%.c
	gcc -g -c $?

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

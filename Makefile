# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmarquar <lmarquar@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/06 13:40:33 by lmarquar          #+#    #+#              #
#    Updated: 2021/07/15 11:10:36 by lmarquar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:= gcc
CFLAGS	:= -Wall -Werror -Wextra
LFLAGS	:= -crs
NAME	:= libftprintf.a
SUBDIR	:= libft/
SUBAR	:= libft/libft.a
PSRC	:= ft_printf.c ft_createstr.c ft_fillist.c \
			 ft_utils.c ft_completelist.c
LOBJ	:= ft_memset.o ft_memcpy.o ft_memccpy.o ft_bzero.o \
			 ft_atoi.o ft_memmove.o ft_memchr.o ft_memcmp.o \
			 ft_strlen.o ft_strlcpy.o ft_strlcat.o ft_strchr.o \
			 ft_strrchr.o ft_strnstr.o ft_strncmp.o ft_isalpha.o \
			 ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o \
			 ft_toupper.o ft_tolower.o ft_calloc.o ft_strdup.o ft_substr.o \
			 ft_strjoin.o ft_strtrim.o ft_split.o ft_itoa.o ft_strmapi.o \
			 ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o
POBJ	:= $(PSRC:.c=.o)

all: $(SUBAR) $(NAME)

re: fclean all

$(NAME): $(LOBJ) $(POBJ)
	ar $(LFLAGS) $@ $(LOBJ) $(POBJ)

$(LOBJ):
	ar -x $(SUBAR)

$(SUBAR):
	cd $(SUBDIR) && make

$(POBJ):
	$(CC) $(CFLAGS) -c $(PSRC)

clean:
	rm -f $(POBJ)
	rm -f $(LOBJ)
	rm -f $(SUBAR)
	cd $(SUBDIR) && make fclean

fclean:
	rm -f $(POBJ)
	rm -f $(LOBJ)
	rm -f $(NAME)
	cd $(SUBDIR) && make fclean
	rm __.SYMDEF\ SORTED
	rm -f a.out

.PHONY: all re clean fclean
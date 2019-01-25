# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gogrkovi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/16 10:44:46 by gogrkovi          #+#    #+#              #
#    Updated: 2018/12/18 17:17:07 by gogrkovi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

SRC = 	ft_strdup.c				\
		ft_strlen.c				\
		ft_strclr.c				\
		ft_strdel.c				\
		ft_strnew.c				\
		ft_tolower.c			\
		ft_toupper.c			\
		ft_isprint.c			\
		ft_isascii.c			\
		ft_isalnum.c			\
		ft_isdigit.c			\
		ft_isalpha.c			\
		ft_memcmp.c				\
		ft_memchr.c				\
		ft_memmove.c			\
		ft_memalloc.c			\
		ft_memdel.c				\
		ft_striter.c			\
		ft_striteri.c			\
		ft_strmap.c				\
		ft_bzero.c				\
		ft_memccpy.c			\
		ft_memcpy.c				\
		ft_memset.c				\
		ft_strchr.c				\
		ft_strrchr.c			\
		ft_strcpy.c				\
		ft_strncpy.c			\
		ft_strcat.c				\
		ft_strncat.c			\
		ft_strlcat.c			\
		ft_strstr.c				\
		ft_strnstr.c			\
		ft_strcmp.c				\
		ft_strncmp.c			\
		ft_atoi.c				\
		ft_strmapi.c			\
		ft_strequ.c				\
		ft_strnequ.c			\
		ft_strsub.c				\
		ft_strjoin.c			\
		ft_strtrim.c			\
		ft_putchar.c			\
		ft_putstr.c				\
		ft_putendl.c			\
		ft_putnbr.c				\
		ft_putchar_fd.c			\
		ft_putstr_fd.c			\
		ft_putendl_fd.c			\
		ft_putnbr_fd.c			\
		ft_strsplit.c			\
		ft_itoa.c				\
		ft_lstdelone.c			\
		ft_lstdel.c				\
		ft_lstiter.c			\
		ft_lstadd.c				\
		ft_lstmap.c				\
		ft_lstnew.c				\
		ft_strcapitalize.c		\
		ft_swap.c				\
		ft_split_whitespaces.c	\
		ft_strrev.c				\
		ft_printbit.c			\

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

INCDIRE = ./includes/

all:$(NAME)

$(NAME): $(OBJ)
	@$(CC) -c $(FLAG) $(SRC) -I $(INCDIRE) -g
	@ar rcs $(NAME) $(OBJ)

fclean: clean
	@rm -f $(NAME)

clean:
	@rm -f $(OBJ)

re:	fclean all

.PHONY: all fclean clean re

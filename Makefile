# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gogrkovi <gogrkovi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/19 15:22:51 by gogrkovi          #+#    #+#              #
#    Updated: 2019/01/23 22:17:43 by gogrkovi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	fillit

SRC =   ft_back_cracks.c \
		ft_check_pieces.c \
		ft_creat_tab.c \
		ft_lettre.c \
		ft_nb_caractere_piece.c \
		ft_nb_of_piece.c \
		ft_place_etoile_piece.c \
		ft_make.c \
		main.c \


OBJ =   $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all:$(NAME)

$(NAME): $(OBJ)
		@make -C libft/
		@$(CC) $(CFLAGS) ./libft/libft.a $(SRC) -o $(NAME)

fclean: clean
		@rm -f $(NAME)
		@make -C libft/ fclean

clean:
		@rm -f $(OBJ)
		@make -C libft/ clean

re:     fclean all

.PHONY: all fclean clean re

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogrkovi <gogrkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:27:54 by gogrkovi          #+#    #+#             */
/*   Updated: 2019/01/18 00:19:10 by gogrkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/includes/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>

typedef struct	s_etris
{
	char		**tetri;
	int			nb;
}				t_etris;

# define BUFF_SIZE 4096

t_etris			*ft_make_struct(char **tab, int piece, t_etris *stock);
void			ft_lettre(t_etris *stock);
char			**ft_createmap(int piece, char **map);
int				ft_nb_of(char **str, int i, int count, int flag);
int				ft_nb_of_y(char **str, int i);
int				check(char *tmp, int i, int *piece, int d);
char			**ft_place_etoile_piece(char **tab, int piece, int x, int y);
int				ft_backcrack(char **map, int nt, t_etris *stock);
char			**ft_creattab(char **tab, int i);
void			*ft_free(char **tab, int nt);
void			ft_print_words_tables(char **tab);
int				ft_check(char **map, t_etris *stock, int x, int y);
int				ft_sqrt(int nb);
char			*ft_rpetoile(char *s, size_t n);
#endif

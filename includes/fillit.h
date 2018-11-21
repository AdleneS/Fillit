/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/05 11:34:57 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2018/11/05 11:34:58 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF 22
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct		s_map
{
	char		**map;
	int			size;
}					t_map;

typedef struct		s_fill
{
	char			**content;
	int				id;
	int				sharp[4][2];
	struct s_fill	*next;
}					t_fill;

t_fill				*file_reader(int fd, t_fill *lst);
int					count_piece(t_fill *orilst);
int					fill_solve(t_map *map, t_fill *lst);
int					fill_check(char *piece);
int					last_check(t_fill *lst);
int					fillit_algo(t_fill *orilst, t_map *map);
int					fill_error(void);
void				display(char **tab);
char				**fillit_map(int ssize);
int					ft_nline(char **map, t_fill *lst, int i, int j);
void				find_first_sharp(t_fill *lst);
int					fill_fit(t_map *map, t_fill *lst, int i, int j);
int					fill_map(t_map *map, t_fill *lst, int i, int j);
int					fill_clean_previous(t_fill *lst, t_map *map, int i, int j);
char				**fillit_map(int ssize);

#endif

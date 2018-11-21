/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/05 11:34:53 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2018/11/05 11:34:54 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_fill	*lst;
	t_map	*map;
	int		pass;
	int		count;

	pass = 0;
	count = 0;
	lst = NULL;
	if (!(map = malloc(sizeof(t_map))))
		return (0);
	if (argc != 2)
		return (0);
	if (!(lst = file_reader(open(argv[1], O_RDONLY), lst)))
		return (fill_error());
	if (count_piece(lst) > 26)
		return (fill_error());
	fill_solve(map, lst);
	return (0);
}

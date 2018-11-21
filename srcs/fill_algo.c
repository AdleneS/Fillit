/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_algo.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 09:00:37 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2018/11/08 09:00:39 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		fill_solve(t_map *map, t_fill *lst)
{
	map->size = ft_sqrt((count_piece(lst) * 4));
	map->map = fillit_map(map->size);
	while (!(fillit_algo(lst, map)))
	{
		ft_memdel((void **)map->map);
		map->size++;
		map->map = fillit_map(map->size);
	}
	display(map->map);
	return (1);
}

int		fill_clean_previous(t_fill *lst, t_map *map, int i, int j)
{
	int		count;

	count = -1;
	if (lst == NULL)
		return (1);
	while (++count < 4)
		map->map[lst->sharp[count][0] + i][lst->sharp[count][1] + j] = '.';
	return (1);
}

int		fillit_algo(t_fill *orilst, t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (orilst == NULL)
		return (1);
	while (map->map[i])
	{
		while (map->map[i][j])
		{
			if (fill_map(map, orilst, i, j))
			{
				if (!(fillit_algo(orilst->next, map)))
					fill_clean_previous(orilst, map, i, j);
				else
					return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_checkfit.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 15:20:49 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 15:20:51 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		fill_fit(t_map *map, t_fill *lst, int i, int j)
{
	int		count;

	count = 0;
	while (map->size > lst->sharp[count][0]
	+ i && map->size > lst->sharp[count][1] + j)
	{
		if (map->map[lst->sharp[count][0] + i][lst->sharp[count][1] + j] == '.')
			count++;
		else
			return (0);
		if (count == 4)
			return (1);
	}
	return (0);
}

int		fill_map(t_map *map, t_fill *lst, int i, int j)
{
	int		count;

	count = 0;
	if (fill_fit(map, lst, i, j))
	{
		while (count < 4 && map->size > lst->sharp[count][0]
		+ i && map->size > lst->sharp[count][1] + j)
		{
			map->map[lst->sharp[count][0] + i]
			[lst->sharp[count][1] + j] = 'A' + lst->id;
			count++;
		}
	}
	else
		return (0);
	return (1);
}

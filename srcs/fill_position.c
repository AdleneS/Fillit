/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_position.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 12:25:47 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2018/11/14 12:25:48 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		set_pos(t_fill *lst, int pos[4], int count)
{
	lst->sharp[count][0] = pos[0] - pos[2];
	lst->sharp[count][1] = pos[1] - pos[3];
	return (0);
}

void	position_fix(int count, int pos[4])
{
	if (count == 0)
	{
		pos[2] = pos[0];
		pos[3] = pos[1];
	}
}

void	find_first_sharp(t_fill *lst)
{
	int		pos[4];
	int		count;

	pos[0] = 0;
	pos[1] = 0;
	pos[2] = 0;
	pos[3] = 0;
	count = 0;
	while (lst->content[pos[0]])
	{
		while (lst->content[pos[0]][pos[1]])
		{
			if (lst->content[pos[0]][pos[1]] == '#')
			{
				position_fix(count, pos);
				set_pos(lst, pos, count);
				count++;
			}
			pos[1]++;
		}
		pos[1] = 0;
		pos[0]++;
	}
}

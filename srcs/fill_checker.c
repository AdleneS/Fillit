/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_checker.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/06 14:59:08 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2018/11/06 14:59:09 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		checkchar(char *piece, int countd, int countp)
{
	int		i;

	i = -1;
	if (piece[0] != '#' && piece[0] != '.')
		return (0);
	while (piece[++i])
	{
		if (piece[i] == '#')
			countd++;
		if (piece[i] == '.')
			countp++;
	}
	if (countd != 4 || countp != 12)
		return (0);
	return (countd);
}

int		count_piece(t_fill *orilst)
{
	int		count;
	t_fill	*tmp;

	count = 0;
	tmp = orilst;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

int		check_nexto(char *piece, int i, int count)
{
	if (count != 0 && !(piece[i + 1] == '#' || piece[i + 5] == '#'
	|| piece[i + 4] == '#' || piece[i + 3] == '#'))
		return (0);
	else if (count == 0 && !(piece[i - 1] == '#' || piece[i - 5] == '#'))
		return (0);
	return (1);
}

int		fill_check(char *piece)
{
	int		countp;
	int		countd;
	int		i;

	countd = 0;
	countp = 0;
	i = 0;
	if (!(countd = checkchar(piece, countd, countp)))
		return (-1);
	while (piece[i])
	{
		if ((piece[i] != '#' && piece[i] != '.' && piece[i] != '\n'))
			return (-1);
		if (piece[i] == '#')
			if (!(check_nexto(piece, i, --countd)))
				return (-1);
		i++;
	}
	return (1);
}

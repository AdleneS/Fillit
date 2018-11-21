/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_utility.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 10:44:06 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2018/11/21 10:44:08 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char		**fillit_map(int ssize)
{
	char	**tab;
	int		i;

	i = -1;
	if (!(tab = (char **)malloc(sizeof(*tab) * ssize + 1)))
		return (NULL);
	while (++i < ssize)
	{
		if (!(tab[i] = ft_strnew(ssize)))
			return (NULL);
		ft_memset(tab[i], '.', ssize);
	}
	tab[i] = 0;
	return (tab);
}

void		display(char **tab)
{
	while (*tab)
	{
		ft_putendl(*tab);
		tab++;
	}
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_reader.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/05 11:41:09 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2018/11/05 11:41:10 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int			addlst(t_fill **lst, char *piece, int count)
{
	t_fill *lsttmp;
	t_fill *tmp;

	if (!(tmp = (t_fill *)malloc(sizeof(t_fill))))
		return (0);
	tmp->content = ft_strsplit(piece, '\n');
	tmp->id = count;
	tmp->next = NULL;
	lsttmp = *lst;
	if (*lst == NULL)
		*lst = tmp;
	else
	{
		while (lsttmp->next)
			lsttmp = lsttmp->next;
		lsttmp->next = tmp;
	}
	find_first_sharp(tmp);
	return (1);
}

t_fill		*file_reader(int fd, t_fill *lst)
{
	int		i;
	int		count;
	char	buff[BUFF];

	i = 0;
	count = 0;
	if (read(fd, &buff, 0) < 0)
		return (NULL);
	while ((i = read(fd, buff, 21)))
	{
		buff[i] = '\0';
		if ((fill_check(buff) == -1))
			return (NULL);
		if (!(addlst(&lst, buff, count)))
			break ;
		count++;
	}
	if (ft_strlen(buff) != 20)
		return (NULL);
	return (lst);
}

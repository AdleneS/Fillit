/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 10:46:54 by asaba        #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 15:13:14 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wordlen(char const *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!s)
		return (0);
	while ((char)s[i] == c && s[i])
		i++;
	while ((char)s[i] != c && s[i])
	{
		i++;
		len++;
	}
	return (len);
}

static int		ft_countwords(char const *s, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while ((char)s[i] == c)
			i++;
		if ((char)s != c && s[i])
			count++;
		while ((char)s[i] != c && s[i])
			i++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ptr;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	if (!s || !(ptr = (char **)malloc(sizeof(*ptr)
					* (ft_countwords(s, c) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_countwords(s, c))
	{
		k = 0;
		if (!(ptr[i] = ft_strnew(ft_wordlen(&s[j], c) + 1)))
			ptr[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			ptr[i][k++] = s[j++];
		ptr[i][k] = '\0';
	}
	ptr[i] = 0;
	return (ptr);
}

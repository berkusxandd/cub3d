/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:38:39 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/05/20 20:05:01 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cw(char const *s, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			cnt++;
		i++;
	}
	return (cnt);
}

static size_t	ft_fill(char **dest, char const *s, char c, size_t i)
{
	size_t	j;

	j = i;
	while (s[j] && s[j] != c)
		j++;
	*dest = (char *)malloc((j - i + 1) * sizeof(char));
	if (!*dest)
		return (0);
	ft_strlcpy(*dest, s + i, j - i + 1);
	return (j);
}

static void	ft_free(char **dest, size_t w)
{
	while (w > 0)
		free(dest[--w]);
	free(dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	size_t	w;
	size_t	i;

	dest = (char **)malloc((ft_cw(s, c) + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	i = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			i = ft_fill(&dest[w++], s, c, i);
			if (!i)
			{
				ft_free(dest, w);
				return (NULL);
			}
		}
		else
			i++;
	}
	dest[w] = NULL;
	return (dest);
}
/*
int	main(void)
{
	char	**dest;
	char	*src;
	char	c;
	int		i;

	src = "asdada a b 12sd1r cd xy  ";
	c = ' ';
	dest = ft_split(src, c);
	i = 0;
	while (dest[i])
	{
		printf("%s\n", dest[i]);
		free(dest[i]);
		i++;
	}
	free(dest);
	return (0);
}
*/

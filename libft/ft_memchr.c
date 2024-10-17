/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:40:49 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/05/17 18:22:14 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*s2;

	s2 = s;
	i = 0;
	while (i < n)
	{
		if (s2[i] == (unsigned char) c)
			return ((void *) s2 + i);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	str[]= "livre1 livre2";
	char	c = 'v';
	char	*c2;
	char	*c3;

	c2 = (char *) ft_memchr(str, c, sizeof(str));
	c3 = (char *) memchr(str, c, sizeof(str));

	printf("%c\n%c\n", c2[0], c3[0]);
	return (0);
}*/

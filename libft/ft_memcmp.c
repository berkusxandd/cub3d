/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:19:19 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/05/22 17:33:59 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*c1;
	const unsigned char	*c2;

	c1 = (const unsigned char *) s1;
	c2 = (const unsigned char *) s2;
	i = 0;
	while (i < n && c1[i] == c2[i])
		i++;
	if (i == n)
		return (0);
	return (c1[i] - c2[i]);
}
/*
int	main(void)
{
	char str1[] = " asd", str2[] = "zxczc", str3[] = "asdasd";
	printf("%d\n", memcmp(str1, str2, 3));
	printf("%d\n", ft_memcmp(str1, str2, 3));
	printf("%d\n", memcmp(str1, str3, 0));
	printf("%d\n", ft_memcmp(str1, str3, 0));
	return (0);
}*/

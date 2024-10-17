/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:04:27 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/05/21 17:07:45 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n--)
	{
		*p = c;
		p++;
	}
	return (s);
}
/*
int	main(void)
{
	int	a1[] = {1, 2, 3, 4};
	int	a2[] = {1, 2, 3, 4};
	
	char	str1[] = "livre1";
	char	str2[] = "livre1";
	
	ft_memset(str1, '*', 5);
	memset(str2, '*', 5);
	printf("%s\n", str1);
	printf("%s\n", str2);
	
	printf("%d\n", a1[1]);
	printf("%d\n", a2[1]);

	ft_memset(a1 + 1, 0, 3);
	memset(a2 + 1, 0, 3);
	
	printf("%d\n", a1[1]);
	printf("%d\n", a2[1]);

	
	return (0);
}*/

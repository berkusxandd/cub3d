/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:04:27 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/05/19 17:36:52 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <strings.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n--)
		*p++ = 0;
}
/*
int	main(void)
{
	int	a1[] = {1, 2, 3, 4};
	int	a2[] = {1, 2, 3, 4};
	
	char	str1[] = "livre1";
	char	str2[] = "livre1";
	
	ft_bzero(str1, 4);
//	bzero(str2, 4);
	printf("%s\n", str1);
	printf("%s\n", str2);
	
	ft_bzero(a1, sizeof(a1));
//	bzero(a2, 16);
	printf("%d\n", a1[1]);
	printf("%d\n", a2[1]);

	
	return (0);
}*/

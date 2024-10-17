/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:04:27 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/05/22 17:30:34 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = dest;
	s = src;
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		d += (n - 1);
		s += (n - 1);
		while (n--)
			*d-- = *s--;
	}
	return (dest);
}
/*
int	main(void)
{
	char	str1[] = "Hello les BG";
	char	str2[] = "Hello les BG";

	ft_memmove(str1 + 3, str1, 5);
	memmove(str2 + 3, str2, 5);
	printf("%s\n", str1);
	printf("%s\n", str2);
	return (0);
}*/

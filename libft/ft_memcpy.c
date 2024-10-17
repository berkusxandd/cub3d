/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:04:27 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/05/22 16:55:14 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!src && !dest)
		return (NULL);
	d = dest;
	s = src;
	while (n--)
		*d++ = *s++;
	return (dest);
}

// int	main(void)
// {
// 	//char	str1[10];
// 	//char	str2[] = "Hello les BG";
// 	//char	str3[10];
// 	//char	str4[] = "Hello les BG";

// 	ft_memcpy(((void*)0), ((void*)0), 3);
// 	//memcpy(((void*)0), ((void*)0), 3);
// 	//printf("%s\n", str1);
// 	//printf("%s\n", str3);
// 	return (0);
// }

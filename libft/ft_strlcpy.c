/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:04:27 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/05/22 11:45:07 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>
#include "libft.h"
//#include <bsd/string.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len;
	size_t	copy_s;

	if (size == 0)
		return (ft_strlen(src));
	len = ft_strlen(src);
	if (len < size)
		copy_s = len;
	else
		copy_s = size - 1;
	ft_memcpy(dest, src, copy_s);
	dest[copy_s] = '\0';
	return (len);
}
/*
int	main(void)
{
	char	dest1[5];
	char	dest2[5];
	const char	src[] = "lorem ipsum dolor sit amet";
	size_t	len_src1;
	size_t	len_src2;


	len_src1 = ft_strlcpy(dest1, src, sizeof(dest1));
	len_src2 = strlcpy(dest2, src, *sizeof(dest2));


	printf("len_src:%zu,-%s-\n", len_src1, dest1);
	printf("len_src:%zu,-%s-\n", len_src2, dest2);

	return (0);
}
*/

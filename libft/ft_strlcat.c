/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:04:27 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/05/22 13:42:22 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <bsd/string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	copy_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (size <= dest_len)
		return (size + src_len);
	copy_len = size - dest_len - 1;
	if (copy_len > src_len)
		copy_len = src_len;
	ft_memcpy(dest + dest_len, src, copy_len);
	dest[dest_len + copy_len] = '\0';
	return (dest_len + src_len);
}
/*
int	main(void)
{
	char	dest1[10]= "1234";
	char	dest2[10]= "1234";
	const char	src[] = "56789";
	size_t	len_sum1;
	size_t	len_sum2;


	len_sum1 = ft_strlcat(dest1, src, sizeof(dest1));
	len_sum2 = strlcat(dest2, src, sizeof(dest2));


	printf("len_sum:%zu,%s\n", len_sum1, dest1);
	printf("len_sum:%zu,%s\n", len_sum2, dest2);

	return (0);
}
*/

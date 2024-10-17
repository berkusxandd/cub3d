/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:48:14 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/05/22 11:39:41 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	d_len;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (s_len - start > len)
		d_len = len;
	else
		d_len = s_len - start;
	dest = (char *)malloc((d_len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s + start, d_len + 1);
	return (dest);
}
/*
int	main(void)
{
	char	*d1;
	const char	src[] = "123456789";

	d1 = ft_substr(src, 20, 10);
	printf("%s\n", d1);
	return (0);
}*/

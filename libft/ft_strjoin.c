/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:03:36 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/05/22 11:38:04 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	d_len;
	size_t	s1_len;
	size_t	s2_len;
	char	*dest;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	d_len = s1_len + s2_len;
	dest = (char *)malloc((d_len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1, d_len + 1);
	ft_strlcat(dest, s2, d_len + 1);
	return (dest);
}
/*
int	main()
{
	char	s1[] = "123";
	char	s2[] = "456";
	char	*s3;

	s3 = ft_strjoin(s1, s2);
	printf("%s\n", s3);
	return (0);
}
*/

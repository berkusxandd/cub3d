/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:54:01 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/05/22 16:22:18 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <bsd/string.h>

char	*ft_strnstr(const char *str, const char *target, size_t n)
{
	size_t	i;
	size_t	target_l;

	if (*target == '\0')
		return ((char *) str);
	target_l = ft_strlen(target);
	i = 0;
	while (str[i] && i + target_l <= n)
	{
		if (str[i] == target[0] && !ft_strncmp(str + i, target, target_l))
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}

// int	main()
// {
// 	char str1[] = "lorem ipsum dolor sit amet";
// 	char str2[] = "dolor";
// 	size_t len = 15;

// 	printf("M:%s\n", ft_strnstr(str1, str2, len));
// 	printf("O:%s\n", strnstr(str1, str2, len));

// 	return (0);
// }

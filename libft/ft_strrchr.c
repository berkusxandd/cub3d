/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:20:12 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/05/22 14:24:23 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str) + 1;
	while (i-- >= 0)
	{
		if (str[i] == (char) c)
			return ((char *) &str[i]);
	}
	return (0);
}

// int 	main(void)
// {
// 	char	str[] = "abcdce cc c";

// 	printf("-%s-\n", ft_strrchr(str, '\0'));
// 	printf("-%s-\n", strrchr(str, '\0'));
// 	return (0);
// }

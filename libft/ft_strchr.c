/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:20:12 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/05/17 16:10:04 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char) c)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == (char) c)
		return ((char *) &str[i]);
	return (0);
}
/*
int 	main(void)
{
	char	str[] = "abcdce cc c";
	printf("%s\n", ft_strchr(str, 'c'));
	printf("%s\n", strchr(str, 'c'));
	return (0);
}*/

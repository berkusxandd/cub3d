/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:15:44 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/09 16:50:26 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	i;

	dest = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src [i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
// int main(void)
// {
//     char	*str = "";
// 	char	*str2;
// 	char	*str3;
// 	str2 = ft_strdup(str);
// 	str3 = strdup(str);
//         printf("%s\n", str2);
//         printf("%s\n", str3);
//     free(str2);
//     free(str3);
//     return (0);
// }

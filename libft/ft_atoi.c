/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:37:31 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/09 16:50:12 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	number;
	int	sign;
	int	i;

	number = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit((unsigned char) str[i]))
	{
		number = (number * 10 + str[i] - '0');
		i++;
	}
	return (sign * number);
}
/*
int	main()
{
	char	*str1 = "    -44";
	char	*str2 = "357";
	char	*str3 = "";
	char	*str4 = "abc-1234";
	char	*str5 = "0";
	char	*str6 = "-1234abc";
	char	*str7 = "1234abc123";

	printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n\n", ft_atoi(str1), \
	ft_atoi(str2), ft_atoi(str3), ft_atoi(str4), ft_atoi(str5), \
	ft_atoi(str6), ft_atoi(str7));
	printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n", atoi(str1), \
	atoi(str2), atoi(str3), atoi(str4), atoi(str5), \
	atoi(str6), atoi(str7));

	return (0);
}
*/

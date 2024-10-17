/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:37:15 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/05/22 14:55:05 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_n_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	ft_reverse(char *p, int i, int n)
{
	int	temp;

	while (i < n)
	{
		temp = p[i];
		p[i++] = p[n];
		p[n--] = temp;
	}
	if (!p[0] && !p[1])
		p[0] = '0';
}

static void	ft_pre_reverse(char *p, int n_len, int nb)
{
	if (nb == 0)
	{
		p[0] = '0';
		p[1] = '\0';
		return ;
	}
	if (p[0] == '-')
		ft_reverse(p, 1, n_len - 1);
	else
		ft_reverse(p, 0, n_len - 1);
}

char	*ft_itoa(int nb)
{
	int		n_len;
	int		i;
	long	n;
	char	*p;

	n = (long)nb;
	n_len = ft_n_len(n);
	p = (char *)malloc((n_len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		n *= -1;
		p[i++] = '-';
	}
	while (n)
	{
		p[i++] = '0' + n % 10;
		n /= 10;
	}
	p[i] = '\0';
	ft_pre_reverse(p, n_len, nb);
	return (p);
}

// int	main(void)
// {
// 	char	*p;

// 	p = ft_itoa(0);
// 	printf("%c\n", p[0]);
// 	return (0);
// }

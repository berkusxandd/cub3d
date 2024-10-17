/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:53:37 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/05/21 16:24:41 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <fcntl.h>

void	ft_putnbr_fd(int n, int fd)
{
	long	n2;

	n2 = n;
	if (n2 < 0)
	{
		ft_putchar_fd('-', fd);
		n2 = -n2;
	}
	if (n2 / 10)
		ft_putnbr_fd(n2 / 10, fd);
	ft_putchar_fd('0' + n2 % 10, fd);
}
/*
int	main(void)
{
	int	fd;

	ft_putnbr_fd(-12345, STDOUT_FILENO);
	fd = open("out.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (fd == -1)
		return (1);
	ft_putnbr_fd(987654, fd);
	close(fd);
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:53:37 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/05/21 17:08:03 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <fcntl.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		ft_putchar_fd(s[i++], fd);
}
/*
int	main(void)
{
	int	fd;

	ft_putstr_fd("ABCDE FGHI", STDOUT_FILENO);
	fd = open("out.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (fd == -1)
		return (1);
	ft_putstr_fd("YO YO YO", fd);
	close(fd);
	return (0);
}
*/

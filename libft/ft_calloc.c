/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:15:44 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/05/22 17:44:35 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*allocated;

	if ((n == 0 || size == 0) && !(n == 0 && size == 0))
		return (NULL);
	allocated = (void *)malloc (n * size);
	if (!allocated)
		return (NULL);
	ft_bzero(allocated, n * size);
	return (allocated);
}
/*
int main(void)
{
    int i = -1;
    int *array;
    array = ft_calloc (10, sizeof(int));
    while (++i < 10)
        printf("%d - %d\n", i, array[i]);
    free(array);
    return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:33:42 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/05/23 11:08:58 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

// int	main(void)
// {
// 	t_list	*tmp;
// 	t_list	*head;
// 	char	*str[]= {"livre1", "livre2", "livre3"};
// 	int		i;

// 	i = 2;
// 	head = ft_lstnew("livre4");
// 	while (i >= 0)
// 	{
// 		tmp = ft_lstnew(str[i]);
// 		ft_lstadd_front(&head, tmp);
// 		i--;
// 	}
// 	printf("%d\n", ft_lstsize(head));
// 	while (head)
// 	{
// 		printf("%s\n", (char *) head->content);
// 		tmp = head;
// 		head = head->next;
// 		free(tmp);
// 	}
// 	return (0);
// }

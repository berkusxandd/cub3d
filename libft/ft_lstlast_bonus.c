/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:09:42 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/05/23 11:19:38 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
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
// 	printf("%s\n", (char *)ft_lstlast(head)->content);
// 	while (head)
// 	{
// 		tmp = head;
// 		head = head->next;
// 		free(tmp);
// 	}
// 	return (0);
// }

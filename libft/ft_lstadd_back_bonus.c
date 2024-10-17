/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:21:27 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/05/23 13:24:24 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lstlast(*lst);
	tmp->next = new;
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
// 	tmp = ft_lstnew("livre5");
// 	ft_lstadd_back(&head, tmp);
// 	printf("%s\n", (char *)ft_lstlast(head)->content);
// 	while (head)
// 	{
// 		tmp = head;
// 		head = head->next;
// 		free(tmp);
// 	}
// 	return (0);
// }

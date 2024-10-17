/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:14:19 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/05/23 10:32:09 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*mid;
// 	t_list	*last;
// 	t_list	*tmp;

// 	last = ft_lstnew("livre3");
// 	mid = ft_lstnew("livre2");
// 	ft_lstadd_front(&last, mid);
// 	head = ft_lstnew("livre1");
// 	ft_lstadd_front(&mid, head);
// 	while (head)
// 	{
// 		printf("%s\n", (char *)head->content);
// 		tmp = head;
// 		head = head->next;
// 		free(tmp);
// 	}
// 	return (0);
// }

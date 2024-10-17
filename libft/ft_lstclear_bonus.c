/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:27:54 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/05/23 14:14:04 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static void	del(void *content)
// {
// 	free(content);
// }

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst || !del)
		return ;
	tmp = *lst;
	while (tmp)
	{
		tmp2 = tmp->next;
		del(tmp->content);
		free(tmp);
		tmp = tmp2;
	}
	*lst = NULL;
}

// int	main(void)
// {
// 	int		i;
// 	t_list	*new;
// 	t_list	*head;

// 	i = 2;
// 	head = ft_lstnew(ft_strdup("1"));
// 	while (i < 6)
// 	{
// 		new = ft_lstnew(ft_strdup(((char[]){('0' + i), '\0'})));
// 		ft_lstadd_back(&head, new);
// 		i++;
// 	}
// 	printf("%d\n", ft_lstsize(head));
// 	ft_lstclear(&head, del);
// 	if (!head)
// 		printf("Deleted\n");
// 	return (0);
// }

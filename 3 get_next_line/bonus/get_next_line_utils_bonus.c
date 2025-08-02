/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:32:42 by opaulman          #+#    #+#             */
/*   Updated: 2025/07/23 20:44:21 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;
	int		i;

	if (!lst)
		return (NULL);
	i = ft_lstsize(lst);
	last = lst;
	while (i > 1)
	{
		last = last->next;
		i--;
	}
	return (last);
}
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new || !*lst)
	{
		if (!*lst)
			*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	if (!last)
		return ;
	last->next = new;
}
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

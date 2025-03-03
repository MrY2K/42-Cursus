/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:51:04 by achoukri          #+#    #+#             */
/*   Updated: 2024/11/12 21:51:19 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new -> next = *lst;
	*lst = new;
}
/*
int main()
{
	// node1 -> node2 -> node3

	int x = 5;

	t_list	*list = ft_lstnew(ft_strdup("First"));
	ft_lstadd_front(&list, ft_lst_new(ft_strdup("Second")));
 
	while (list)
	{
		printf("%s \n", list->content);
		list = list->next;
	}
	
	// t_list	*node2 = ft_lstnew(sizeof(int));
	// node1->content = 13;

	// t_list	*node3 = ft_lstnew(sizeof(int));
	// node1->content = 37;

	// node1->next = node2;
	// node2->next = node3;

	// node1 -> node2 -> node3
	
}
*/
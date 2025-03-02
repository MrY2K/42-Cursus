/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_manipulation2_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:11:36 by achoukri          #+#    #+#             */
/*   Updated: 2025/02/27 18:58:01 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

t_stack_node	*ft_lstlast(t_stack_node *lst);
void			ft_lstadd_back(t_stack_node **lst, t_stack_node *_new);
size_t			ft_lstsize(t_stack_node *head);

void	ft_lstadd_back(t_stack_node **lst, t_stack_node *_new)
{
	t_stack_node	*last;

	if (lst == NULL || _new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = _new;
	}
	else
	{
		last = ft_lstlast(*lst);
		last->next = _new;
	}
}

t_stack_node	*ft_lstlast(t_stack_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst -> next;
	return (lst);
}

size_t	ft_lstsize(t_stack_node *head)
{
	size_t			i;
	t_stack_node	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

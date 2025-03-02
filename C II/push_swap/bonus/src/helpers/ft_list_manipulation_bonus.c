/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_manipulation_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:11:36 by achoukri          #+#    #+#             */
/*   Updated: 2025/02/27 18:57:58 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

t_stack_node		*ft_lstnew(int data);
int					has_duplicates(t_stack_node *head);
void				ft_lstadd_front(t_stack_node **lst, t_stack_node *new_node);
void				ft_lstclear(t_stack_node **lst);
void				ft_lstdelone(t_stack_node *lst);

t_stack_node	*ft_lstnew(int data)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return (NULL);
	new_node -> data = data;
	new_node -> index = 0;
	new_node -> next = NULL;
	return (new_node);
}

void	ft_lstadd_front(t_stack_node **lst, t_stack_node *new_node)
{
	if (!lst || !new_node)
		return ;
	new_node -> next = *lst;
	*lst = new_node;
}

void	ft_lstclear(t_stack_node **lst)
{
	t_stack_node	*next_node;

	if (!lst)
		return ;
	while (*lst)
	{
		next_node = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = next_node;
	}
}

void	ft_lstdelone(t_stack_node *lst)
{
	if (!lst)
		return ;
	free(lst);
}

int	has_duplicates(t_stack_node *head)
{
	t_stack_node	*current;
	t_stack_node	*checker;

	if (!head)
		return (1);
	current = head;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->data == checker->data)
				return (1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}

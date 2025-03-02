/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:03:15 by achoukri          #+#    #+#             */
/*   Updated: 2025/02/26 20:53:37 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

int				sorted(t_stack_node *stack_a);
void			indexing(t_stack_node *stack_a);
int				get_min_index_pos(t_stack_node *stack_a);
t_stack_node	*max_node(t_stack_node *stack);
int				above_median(t_stack_node *stack, t_stack_node *max_node);

int	sorted(t_stack_node *stack_a)
{
	if (!stack_a)
		return (1);
	while (stack_a->next)
	{
		if (stack_a->data > stack_a->next->data)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	indexing(t_stack_node *stack_a)
{
	t_stack_node	*current;
	t_stack_node	*temp;
	int				count;

	if (!stack_a)
		return ;
	current = stack_a;
	while (current)
	{
		count = 0;
		temp = stack_a;
		while (temp)
		{
			if (current->data > temp->data)
				count++;
			temp = temp->next;
		}
		current->index = count;
		current = current->next;
	}
}

int	get_min_index_pos(t_stack_node *stack_a)
{
	int	pos;

	pos = 0;
	while (stack_a)
	{
		if (stack_a->index == 0)
			return (pos);
		pos++;
		stack_a = stack_a->next;
	}
	return (-1);
}

t_stack_node	*max_node(t_stack_node *stack)
{
	t_stack_node	*max;
	t_stack_node	*current;

	max = stack;
	current = stack;
	while (current != NULL)
	{
		if (current -> data > max -> data)
			max = current;
		current = current -> next;
	}
	return (max);
}

int	above_median(t_stack_node *stack, t_stack_node *max_node)
{
	t_stack_node	*current;
	size_t			count;

	current = stack;
	count = 0;
	while (current != max_node)
	{
		count++;
		current = current -> next;
	}
	if (count <= ft_lstsize(stack) / 2)
		return (1);
	else
		return (0); 
}

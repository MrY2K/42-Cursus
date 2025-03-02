/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:55:26 by achoukri          #+#    #+#             */
/*   Updated: 2025/02/13 18:06:11 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	rr(t_stack_node **stack_a, t_stack_node **stack_b);
int	reverse_rotate(t_stack_node **stack);
int	rra(t_stack_node **stack);
int	rrb(t_stack_node **stack);
int	rrr(t_stack_node **stack_a, t_stack_node **stack_b);

int	rr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (-1);
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
	return (0);
}

int	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*sec_last;
	t_stack_node	*last;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	sec_last = NULL;
	last = *stack;
	while (last->next != NULL)
	{
		sec_last = last;
		last = last->next;
	}
	sec_last->next = NULL;
	last->next = *stack;
	*stack = last;
	return (0);
}

int	rra(t_stack_node **stack)
{
	if (ft_lstsize(*stack) < 2)
		return (-1);
	reverse_rotate(stack);
	write(1, "rra\n", 4);
	return (0);
}

int	rrb(t_stack_node **stack)
{
	if (ft_lstsize(*stack) < 2)
		return (-1);
	reverse_rotate(stack);
	write(1, "rrb\n", 4);
	return (0);
}

int	rrr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (-1);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
	return (0);
}

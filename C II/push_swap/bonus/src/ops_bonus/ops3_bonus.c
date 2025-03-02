/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops3_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:55:26 by achoukri          #+#    #+#             */
/*   Updated: 2025/02/26 20:53:44 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

int	rr(t_stack_node **stack_a, t_stack_node **stack_b);
int	reverse_rotate(t_stack_node **stack);
int	rra(t_stack_node **stack);
int	rrb(t_stack_node **stack);
int	rrr(t_stack_node **stack_a, t_stack_node **stack_b);

int	rr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return (-1);
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (-1);
	rotate(stack_a);
	rotate(stack_b);
	return (0);
}

int	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*sec_last;
	t_stack_node	*last;

	if (stack == NULL || *stack == NULL)
		return (-1);
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
	if (stack == NULL || *stack == NULL)
		return (-1);
	if (ft_lstsize(*stack) < 2)
		return (-1);
	reverse_rotate(stack);
	return (0);
}

int	rrb(t_stack_node **stack)
{
	if (stack == NULL || *stack == NULL)
		return (-1);
	if (ft_lstsize(*stack) < 2)
		return (-1);
	reverse_rotate(stack);
	return (0);
}

int	rrr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return (-1);
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (-1);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	return (0);
}

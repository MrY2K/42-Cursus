/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:53:34 by achoukri          #+#    #+#             */
/*   Updated: 2025/02/22 18:37:34 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pa(t_stack_node **stack_a, t_stack_node **stack_b);
void	pb(t_stack_node **stack_a, t_stack_node **stack_b);
int		rotate(t_stack_node **stack);
int		ra(t_stack_node **stack);
int		rb(t_stack_node **stack);

void	pa(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (!*stack_b)
		return ;
	if (push_top(stack_a, stack_b) == -1)
		return ;
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (!*stack_a)
		return ;
	if (push_top(stack_b, stack_a) == -1)
		return ;
	write(1, "pb\n", 3);
}

int	rotate(t_stack_node **stack)
{
	t_stack_node	*second;
	t_stack_node	*last;

	if (stack == NULL || *stack == NULL)
		return (-1);
	if (ft_lstsize(*stack) < 2)
		return (-1);
	second = (*stack)->next;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = *stack;
	(*stack)->next = NULL;
	(*stack) = second;
	return (0);
}

int	ra(t_stack_node **stack)
{
	if (stack == NULL || *stack == NULL)
		return (-1);
	if (rotate(stack) == -1)
		return (-1);
	write(1, "ra\n", 3);
	return (0);
}

int	rb(t_stack_node **stack)
{
	if (stack == NULL || *stack == NULL)
		return (-1);
	if (rotate(stack) == -1)
		return (-1);
	write(1, "rb\n", 3);
	return (0);
}

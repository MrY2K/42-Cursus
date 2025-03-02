/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops1_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:42:28 by achoukri          #+#    #+#             */
/*   Updated: 2025/02/26 20:53:40 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

int	swap(t_stack_node **stack);
int	sa(t_stack_node **stack);
int	sb(t_stack_node **stack);
int	ss(t_stack_node **stack_a, t_stack_node **stack_b);
int	push_top(t_stack_node **stack_to, t_stack_node **stack_from);

int	swap(t_stack_node **stack)
{
	t_stack_node	*top;
	t_stack_node	*next;
	int				temp_data;

	if (stack == NULL || *stack == NULL)
		return (-1);
	if (ft_lstsize(*stack) < 2)
		return (-1);
	top = *stack;
	next = top->next;
	temp_data = top->data;
	top->data = next->data;
	next->data = temp_data;
	return (0);
}

int	sa(t_stack_node **stack)
{
	if (stack == NULL || *stack == NULL)
		return (-1);
	if (swap(stack) == -1)
		return (-1);
	return (0);
}

int	sb(t_stack_node **stack)
{
	if (swap(stack) == -1)
		return (-1);
	return (0);
}

int	ss(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return (-1);
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (-1);
	swap(stack_a);
	swap(stack_b);
	return (0);
}

int	push_top(t_stack_node **stack_to, t_stack_node **stack_from)
{
	t_stack_node	*temp;

	if (!stack_from || !*stack_from)
		return (-1);
	temp = *stack_from;
	*stack_from = (*stack_from)->next;
	temp->next = *stack_to;
	*stack_to = temp;
	return (0);
}

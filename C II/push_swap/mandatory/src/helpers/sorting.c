/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:18:24 by achoukri          #+#    #+#             */
/*   Updated: 2025/02/22 19:14:09 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sorting_dispatcher(t_stack_node **stack_a, t_stack_node **stack_b);
void	sort_two(t_stack_node **stack_a);
void	sort_three(t_stack_node **stack_a);
void	sort_four(t_stack_node **stack_a, t_stack_node **stack_b);
void	sort_five(t_stack_node **stack_a, t_stack_node **stack_b);

void	sorting_dispatcher(t_stack_node **s_a, t_stack_node **s_b)
{
	int	size;

	size = ft_lstsize(*s_a);
	if (!s_a || !*s_a)
		return ;
	if (size == 2)
		sort_two(s_a);
	else if (size == 3)
		sort_three(s_a);
	else if (size == 4)
		sort_four(s_a, s_b);
	else if (size == 5)
		sort_five(s_a, s_b);
	else if (size <= 100)
		el_rango(s_a, s_b, 15);
	else if (size > 100 && size <= 500)
		el_rango(s_a, s_b, 35);
	else
		el_rango(s_a, s_b, 45);
}

void	sort_two(t_stack_node **stack_a)
{
	if (!stack_a || !*stack_a || !((*stack_a)->next))
		return ;
	if ((*stack_a)->data > (*stack_a)->next->data)
		sa(stack_a);
}

void	sort_three(t_stack_node **stack_a)
{
	int	a;
	int	b;
	int	c;

	if (!stack_a || !*stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
		return ;
	a = (*stack_a)->data;
	b = (*stack_a)->next->data;
	c = (*stack_a)->next->next->data;
	if (a < b && b > c && c < a)
		rra(stack_a);
	else if (a > b && b < c && c > a)
		sa(stack_a);
	else if (a > b && b > c && c < a)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && b < c && c < a)
		ra(stack_a);
	else if (a < b && b > c && c > a)
	{
		sa(stack_a);
		ra(stack_a);
	}
}

void	sort_four(t_stack_node **stack_a, t_stack_node **stack_b)
{
	size_t	min_index;

	min_index = get_min_index_pos(*stack_a);
	if (min_index == 1)
		ra(stack_a);
	else if (min_index == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (min_index == 3)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push_max_into_b(stack_a, stack_b);
	push_max_into_b(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	ra(stack_a);
	pa(stack_a, stack_b);
	ra(stack_a); 
}

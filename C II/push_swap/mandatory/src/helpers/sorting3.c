/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:18:24 by achoukri          #+#    #+#             */
/*   Updated: 2025/02/22 18:47:32 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push_max_into_b(t_stack_node **stack_a, t_stack_node **stack_b);
int		get_position(t_stack_node *b, int max_idx);
void	push_tha_shit_back_to_a_soorted(t_stack_node **s_a, t_stack_node **s_b);
void	el_rango(t_stack_node **s_a, t_stack_node **s_b, int maxi);

void	push_max_into_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*max;

	max = max_node(*stack_a);
	while (*stack_a != max)
	{
		if (above_median(*stack_a, max))
		{
			ra(stack_a);
		}
		else
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}

void	el_rango(t_stack_node **s_a, t_stack_node **s_b, int maxi)
{
	int	mini;

	mini = 0;
	while (*s_a)
	{
		if ((*s_a)->index >= mini && (*s_a)->index <= maxi)
		{
			pb(s_a, s_b);
			mini++;
			maxi++;
		}
		else if ((*s_a)->index < mini)
		{
			pb(s_a, s_b);
			rb(s_b);
			mini++;
			maxi++;
		}
		else
			ra(s_a);
	}
	push_tha_shit_back_to_a_soorted(s_a, s_b);
}

int	get_position(t_stack_node *b, int max_idx)
{
	int	pos;

	pos = 0;
	while (b)
	{
		if (b->index == max_idx)
			return (pos);
		pos++;
		b = b->next;
	}
	return (-1);
}

void	push_tha_shit_back_to_a_soorted(t_stack_node **s_a, t_stack_node **s_b)
{
	int	max_idx;
	int	half_size;
	int	pos;

	while (*s_b)
	{
		max_idx = ft_lstsize(*s_b) - 1;
		half_size = ft_lstsize(*s_b) / 2;
		pos = get_position(*s_b, max_idx);
		if ((*s_b)->index == max_idx)
		{
			pa(s_a, s_b);
		}
		else if (pos > half_size)
		{
			rrb(s_b);
		}
		else
			rb(s_b);
	}
}

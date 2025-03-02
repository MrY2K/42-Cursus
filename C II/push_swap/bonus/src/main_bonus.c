/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:37:38 by achoukri          #+#    #+#             */
/*   Updated: 2025/02/26 20:56:25 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"
#include "../include/get_next_line_bonus.h"

void	ft_clear(t_stack_node **a, t_stack_node **b, char *move);
void	do_the_moves(t_stack_node **a, t_stack_node **b);
int		move_dispatcher(t_stack_node **a, t_stack_node **b, char *move);
void	fill_the_stacky_stack(int ac, char **av, t_stack_node **stack_a);

int	main(int ac, char **av)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	fill_the_stacky_stack(ac, av, &stack_a);
	if (has_duplicates(stack_a) == 1)
	{
		ft_lstclear(&stack_a);
		ft_error();
	}
	do_the_moves(&stack_a, &stack_b);
	if (!stack_b && sorted(stack_a))
	{
		ft_putstr_fd("OK\n", 1);
	}
	else
	{
		ft_putstr_fd("KO\n", 1);
	}
	return (ft_lstclear(&stack_a), ft_lstclear(&stack_b), 0);
}

void	fill_the_stacky_stack(int ac, char **av, t_stack_node **stack_a)
{
	int				total_tokens;
	char			**_valid_args;

	total_tokens = count_tokens(ac, av);
	_valid_args = validate_input(ac, av, total_tokens);
	if (!_valid_args)
		ft_error();
	fill_the_stack(_valid_args, stack_a);
	ft_free_split(_valid_args);
}

void	do_the_moves(t_stack_node **a, t_stack_node **b)
{
	char	*move;

	while (1)
	{
		move = get_next_line(0);
		if (!move)
			break ;
		if (!move_dispatcher(a, b, move))
			ft_clear(a, b, move);
		free(move);
	}
}

int	move_dispatcher(t_stack_node **a, t_stack_node **b, char *move)
{
	if (ft_strncmp(move, "pa\n", 3) == 0)
		return (pa(a, b), 1);
	if (ft_strncmp(move, "pb\n", 3) == 0)
		return (pb(a, b), 1);
	if (ft_strncmp(move, "sa\n", 3) == 0)
		return (sa(a), 1);
	if (ft_strncmp(move, "sb\n", 3) == 0)
		return (sb(b), 1);
	if (ft_strncmp(move, "ss\n", 3) == 0)
		return (ss(a, b), 1);
	if (ft_strncmp(move, "ra\n", 3) == 0)
		return (ra(a), 1);
	if (ft_strncmp(move, "rb\n", 3) == 0)
		return (rb(b), 1);
	if (ft_strncmp(move, "rr\n", 3) == 0)
		return (rr(a, b), 1);
	if (ft_strncmp(move, "rra\n", 4) == 0)
		return (rra(a), 1);
	if (ft_strncmp(move, "rrb\n", 4) == 0)
		return (rrb(b), 1);
	if (ft_strncmp(move, "rrr\n", 4) == 0)
		return (rrr(a, b), 1);
	return (0);
}

void	ft_clear(t_stack_node **a, t_stack_node **b, char *move)
{
	ft_lstclear(a);
	ft_lstclear(b);
	free(move);
	ft_error();
}

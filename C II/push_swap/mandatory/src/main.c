/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:38:15 by achoukri          #+#    #+#             */
/*   Updated: 2025/02/17 11:58:21 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	char			**_valid_args;
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	int				total_tokens;

	stack_a = NULL;
	stack_b = NULL;
	total_tokens = count_tokens(ac, av);
	_valid_args = validate_input(ac, av, total_tokens);
	if (!_valid_args)
		ft_error();
	fill_the_stack(_valid_args, &stack_a);
	ft_free_split(_valid_args);
	if (has_duplicates(stack_a) == 1)
	{
		ft_lstclear(&stack_a);
		ft_error();
	}
	if (sorted(stack_a) == 1)
		sorted_exit(&stack_a);
	indexing(stack_a);
	sorting_dispatcher(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	return (0);
}

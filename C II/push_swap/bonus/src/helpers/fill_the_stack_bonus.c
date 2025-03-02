/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_the_stack_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:37:44 by achoukri          #+#    #+#             */
/*   Updated: 2025/02/26 20:53:15 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

void	fill_the_stack(char **_valid_args, t_stack_node **stack_a)
{
	int	i;

	i = -1;
	while (_valid_args[++i])
		ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(_valid_args[i])));
}

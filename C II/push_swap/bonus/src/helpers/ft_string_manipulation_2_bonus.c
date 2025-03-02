/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_manipulation_2_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:56:14 by achoukri          #+#    #+#             */
/*   Updated: 2025/02/27 18:58:03 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

int	count_tokens(int ac, char **av)
{
	int		total;
	int		i;
	char	*p;
	int		count;

	total = 0;
	i = 0;
	while (++i < ac)
	{
		count = 0;
		p = av[i];
		while (*p)
		{
			if (*p == ' ')
				count++;
			p++;
		}
		total += count + 1;
	}
	return (total);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_input2_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:17:11 by achoukri          #+#    #+#             */
/*   Updated: 2025/02/26 20:53:33 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

void	ft_check_max(char *arg, int sign);

void	ft_check_max(char *arg, int sign)
{
	long	n;

	n = ft_atoi(arg);
	if ((n > 2147483647 && sign == 1) && (n > 2147483648 && sign == -1))
	{
		ft_error();
	}
}

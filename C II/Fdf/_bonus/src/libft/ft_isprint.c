/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:02:25 by achoukri          #+#    #+#             */
/*   Updated: 2025/03/12 00:19:34 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	else
		return (0);
}
/*
int main(void)
{
	char c = 129;
	
	if (ft_isprint((unsigned char) c))
	{
		printf("Your input is printable.\n");
	}
	else
	{
		printf("Your input is not printable.\n");
	}

	return 0;
}
*/
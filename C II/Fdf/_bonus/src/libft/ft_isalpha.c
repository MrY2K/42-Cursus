/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:02:19 by achoukri          #+#    #+#             */
/*   Updated: 2025/03/12 00:19:25 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
		return (0);
}
/*
int main(void)
{
	char c = '9';
	
	if (ft_isalpha((unsigned char) c))
	{
		printf("Your input is alphabitic.\n");
	}
	else
	{
		printf("Your input is not alphabitic.\n");
	}

	return 0;
}
*/
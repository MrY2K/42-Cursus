/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:02:17 by achoukri          #+#    #+#             */
/*   Updated: 2024/10/29 13:53:44 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') 
		|| (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
		return (0);
}
/*
int main(void)
{
	char c = '-';
	
	if (ft_isalnum((unsigned char) c))
	{
		printf("Your input is alphanumiric.\n");
	}
	else
	{
		printf("Your input is not alphanumiric.\n");
	}

	return 0;
}
*/
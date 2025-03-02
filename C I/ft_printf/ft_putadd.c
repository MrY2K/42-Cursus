/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:44:00 by achoukri          #+#    #+#             */
/*   Updated: 2024/12/06 21:19:31 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadd(void *add)
{
	unsigned long	nbr_l;
	int				count;

	nbr_l = (unsigned long)add;
	count = 0;
	count += ft_putstr("0x");
	count += ft_putnbr_hex(nbr_l, 'x');
	return (count);
}

// #include <stdio.h>
// int main()
// {
// 	void *ptr;
// 	int m = ft_putadd(ptr);
// 	printf("\n\n");
// 	int o = printf("%p", ptr);
// 	printf("\n\n%d  %d \n\n", m, o);
// }

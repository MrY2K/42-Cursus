/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:46:33 by achoukri          #+#    #+#             */
/*   Updated: 2024/12/06 21:17:52 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648) 
	{
		count += ft_putchar('-');
		count += ft_putchar('2');
		n = 147483648;
	}
	else if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		count += ft_putnbr(n / 10);
		count += ft_putchar((n % 10) + 48);
	}
	else
	{
		count += ft_putchar(n + 48);
	}
	return (count);
}

// int main()
// {
// 	ft_putnbr_fd(-2147483648, 0);
// 	ft_putnbr_fd(2147483647, 0);
// 	ft_putnbr_fd(0, 0);
// }
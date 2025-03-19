/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:22:35 by achoukri          #+#    #+#             */
/*   Updated: 2025/03/12 00:15:08 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf_bonus.h"

int	hex_to_int(const char *hex);
int	ft_atoi_base(const char *str, int str_base);
int	ft_isvalid(char c, int base);

int	ft_isvalid(char c, int base)
{
	char	*digits;
	char	*digits2;
	int		i;

	digits = "0123456789abcdef";
	digits2 = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (0);
	i = 0;
	while (i < base)
	{
		if (digits[i] == c || digits2[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	sign;
	int	res;
	int	i;

	sign = 1;
	res = 0;
	i = -1;
	if (str[++i] == '-')
		sign = -1;
	while (str[i])
	{
		if (!ft_isvalid(str[i], str_base))
			break ;
		res = res * str_base;
		if (('0' <= str[i]) && (str[i] <= '9'))
			res = res + (str[i] - '0');
		else if ((str[i] >= 'A') && (str[i] <= 'Z'))
			res = res + (str[i] - 'A' + 10);
		else if ((str[i] >= 'a') && (str[i] <= 'z'))
			res = res + (str[i] - 'a' + 10);
		i++;
	}
	return (res * sign);
}

int	hex_to_int(const char *hex)
{
	if (!hex || !*hex)
		ft_error("Empty hex string");
	if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X'))
		hex += 2;
	return (ft_atoi_base(hex, 16));
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

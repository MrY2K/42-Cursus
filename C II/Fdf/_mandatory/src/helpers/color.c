/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:05:22 by achoukri          #+#    #+#             */
/*   Updated: 2025/03/10 22:02:17 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	assign_colors_to_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->grid[i][j].color = get_color(map->grid[i][j].z, map);
			map->grid[i][j].color = get_color(map->grid[i][j].z, map);
			j++;
		}
		i++;
	}
}

int	get_color(int z, t_map *map)
{
	int			z_min;
	int			z_max;
	double		ratio;
	int			red;
	int			blue;

	ratio = 0.0;
	z_min = map->z_min;
	z_max = map->z_max;
	if (z_max > z_min)
		ratio = (double)(z - z_min) / (z_max - z_min);
	red = (int)(255 * ratio);
	blue = (int)(255 * (1 - ratio));
	return ((red << 24) | (GREEN << 16) | (blue << 8) | 0xFF);
}

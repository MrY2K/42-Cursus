/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 23:38:41 by achoukri          #+#    #+#             */
/*   Updated: 2025/03/12 00:15:27 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	draw_a_pixel(int x, int y, mlx_image_t *img, int color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) 
	{
		mlx_put_pixel(img, x, y, color);
	}
}

void	draw_wireframe(t_map *map, t_mlx *mlx, t_view_params *v)
{
	t_point2d	p;
	t_point2d	p_right;
	t_point2d	p_down;
	int			i;
	int			j;

	i = -1; 
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			p = proj_disp(i, j, map->grid[i][j].z, v);
			if (j < map->width - 1)
			{
				p_right = proj_disp(i, j + 1, map->grid[i][j + 1].z, v);
				bresenham(p, p_right, mlx->img, map->grid[i][j].color);
			}
			if (i < map->height - 1)
			{
				p_down = proj_disp(i + 1, j, map->grid[i + 1][j].z, v);
				bresenham(p, p_down, mlx->img, map->grid[i][j].color);
			}
		}
	}
}

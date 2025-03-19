/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 23:37:38 by achoukri          #+#    #+#             */
/*   Updated: 2025/03/11 22:00:10 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static t_line_params	init_line_params(t_point2d start, t_point2d end)
{
	t_line_params	line;

	line.steep = abs(end.y - start.y) > abs(end.x - start.x);
	if (line.steep)
	{
		ft_swap(&start.x, &start.y);
		ft_swap(&end.x, &end.y);
	}
	line.x0 = start.x;
	line.y0 = start.y;
	line.x1 = end.x;
	line.y1 = end.y;
	line.dx = fabs((float)end.x - (float)start.x);
	line.dy = fabs((float)end.y - (float)start.y);
	if (line.x0 < line.x1)
		line.sx = 1;
	else
		line.sx = -1;
	if (line.y0 < line.y1)
		line.sy = 1;
	else
		line.sy = -1;
	line.err = 2 * line.dy - line.dx;
	return (line);
}

static void	draw_line(t_line_params line, mlx_image_t *img, int color)
{
	int	i;

	i = 0;
	while (i <= line.dx)
	{
		if (line.steep)
			draw_a_pixel(line.y0, line.x0, img, color);
		else
			draw_a_pixel(line.x0, line.y0, img, color);
		if (line.err > 0)
		{
			line.y0 += line.sy;
			line.err -= 2 * line.dx;
		}
		line.err += 2 * line.dy;
		line.x0 += line.sx;
		i++;
	}
}

void	bresenham(t_point2d st, t_point2d end, mlx_image_t *img, int col)
{
	t_line_params	line;

	line = init_line_params(st, end);
	draw_line(line, img, col);
}

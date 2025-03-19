/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 23:38:41 by achoukri          #+#    #+#             */
/*   Updated: 2025/03/16 00:03:13 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf_bonus.h"

void	draw_a_pixel(int x, int y, mlx_image_t *img, int color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) 
	{
		mlx_put_pixel(img, x, y, color);
	}
}

void	draw_wireframe( t_mlx *mlx)
{
	t_point2d	p;
	t_point2d	p_right;
	t_point2d	p_down;
	int			i;
	int			j;

	i = -1; 
	while (++i < mlx->height)
	{
		j = -1;
		while (++j < mlx->width)
		{
			p = proj_disp(i, j, mlx->grid[i][j].z, mlx);
			if (j < mlx->width - 1)
			{
				p_right = proj_disp(i, j + 1, mlx->grid[i][j + 1].z, mlx);
				bresenham(p, p_right, mlx->img, mlx->grid[i][j].color);
			}
			if (i < mlx->height - 1)
			{
				p_down = proj_disp(i + 1, j, mlx->grid[i + 1][j].z, mlx);
				bresenham(p, p_down, mlx->img, mlx->grid[i][j].color);
			}
		}
	}
}

void	apply_rotation(double *x, double *y, double *z, t_mlx *mlx)
{
	double	_y;
	double	_x;

	_y = *y;
	*y = _y * cos(to_radians(mlx->r_x)) + *z * sin(to_radians(mlx->r_x));
	*z = -_y * sin(to_radians(mlx->r_x)) + *z * cos(to_radians(mlx->r_x));
	_x = *x;
	*x = _x * cos(to_radians(mlx->r_y)) + *z * sin(to_radians(mlx->r_y));
	*z = -_x * sin(to_radians(mlx->r_y)) + *z * cos(to_radians(mlx->r_y));
	_x = *x;
	_y = *y;
	*x = _x * cos(to_radians(mlx->r_z)) - _y * sin(to_radians(mlx->r_z));
	*y = _x * sin(to_radians(mlx->r_z)) + _y * cos(to_radians(mlx->r_z));
}

void	ft_auto_rotation(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (mlx->autorotation)
	{
		mlx->r_z += 0.5;
		clear_image(mlx->img);
		draw_wireframe(mlx);
	}
}

void	clear_image(mlx_image_t *img)
{
	ft_memset(img->pixels, 0, img->width * img->height * sizeof(int));
}

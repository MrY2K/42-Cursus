/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 02:03:45 by achoukri          #+#    #+#             */
/*   Updated: 2025/03/16 00:07:38 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf_bonus.h"

t_point2d	proj_disp(int i, int j, int z, t_mlx *mlx)
{
	if (mlx->projection == 0)
		return (project_parallel(i, j, mlx));
	else if (mlx->projection == 1) 
		return (project_simple_isometric(i, j, z, mlx));
	else if (mlx->projection == 2)
		return (project_true_isometric(i, j, z, mlx));
	else
	{
		mlx->projection = 0;
		return (project_parallel(i, j, mlx));
	}
}

t_point2d	project_simple_isometric(int i, int j, int z, t_mlx *mlx)
{
	t_point2d	pt;
	double		x;
	double		y;
	double		z_val;

	x = j - mlx->width / 2.0;
	y = i - mlx->height / 2.0;
	z_val = z;
	apply_rotation(&x, &y, &z_val, mlx);
	x += mlx->width / 2.0;
	y += mlx->height / 2.0;
	pt.x = (x - y) * mlx->scale + mlx->x_offset;
	pt.y = (x + y) * mlx->scale / 2 - z * mlx->elevation + mlx->y_offset;
	return (pt);
}

t_point2d	project_true_isometric(int i, int j, int z, t_mlx *m)
{
	t_point2d	pt;
	double		x;
	double		y; 
	double		z_val;
	double		angle;

	x = j - m->width / 2.0;
	y = i - m->height / 2.0;
	z_val = z;
	apply_rotation(&x, &y, &z_val, m);
	x += m->width / 2.0;
	y += m->height / 2.0;
	angle = to_radians(30);
	pt.x = (x - y) * cos(angle) * m->scale + m->x_offset;
	pt.y = (x + y) * m->scale * sin(angle) - z * m->elevation + m->y_offset;
	return (pt);
}

t_point2d	project_parallel(int i, int j, t_mlx *mlx)
{
	t_point2d	pt;

	pt.x = j * mlx->scale + mlx->x_offset;
	pt.y = i * mlx->scale + mlx->y_offset;
	return (pt);
}

double	to_radians(double degrees)
{
	return (degrees * (M_PI / 180.0));
}

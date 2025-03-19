/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 00:56:47 by achoukri          #+#    #+#             */
/*   Updated: 2025/03/16 00:21:20 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf_bonus.h"

void	initialize_view_elev(t_mlx *mlx)
{
	float		avg_dim;
	float		k;

	mlx->autorotation = 0;
	avg_dim = ((float)mlx->width + (float)mlx->height) / 2.0f;
	if (avg_dim <= 20)
		k = 10;
	else if (avg_dim <= 40)
		k = 50;
	else if (avg_dim <= 60)
		k = 70;
	else
		k = 100;
	mlx->elevation = mlx->scale * (k / avg_dim);
	if (mlx->elevation < 1)
		mlx->elevation = 1;
}

void	initialize_view(t_mlx *mlx)
{
	float		scale_x;
	float		sc_y;
	int			i_center;
	int			j_center;
	t_point2d	center_projected;

	mlx->x_offset = 0;
	mlx->y_offset = 0;
	mlx->r_x = 0;
	mlx->r_y = 0; 
	mlx->r_z = 0;
	scale_x = (WIDTH * PADING) / ((float)mlx->width + (float)mlx->height);
	sc_y = (HEIGHT * PADING) / (((float)mlx->width + (float)mlx->height) / 2);
	mlx->scale = fmin(scale_x, sc_y);
	initialize_view_elev(mlx);
	i_center = mlx->height / 2;
	j_center = mlx->width / 2;
	center_projected = project_parallel(i_center, j_center, mlx);
	mlx->x_offset = (WIDTH / 2) - center_projected.x + 200;
	mlx->y_offset = (HEIGHT / 2) - center_projected.y;
}

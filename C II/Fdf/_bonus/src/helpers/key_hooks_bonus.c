/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:11:35 by achoukri          #+#    #+#             */
/*   Updated: 2025/03/16 00:09:15 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf_bonus.h"

void	_clear_draw(t_mlx *mlx)
{
	clear_image(mlx->img);
	draw_wireframe(mlx);
}

void	key_hooks(struct mlx_key_data keydata, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(mlx->ptr);
	move_and_projct_keys(keydata, mlx);
	scale_and_elev(keydata, mlx);
	rotation_keys(keydata, mlx);
	if (keydata.key == MLX_KEY_T && keydata.action == MLX_PRESS)
	{
		initialize_view(mlx);
		_clear_draw(mlx);
	}
}

void	move_and_projct_keys(struct mlx_key_data keydata, t_mlx *mlx)
{
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		mlx->x_offset += 10;
		_clear_draw(mlx);
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		mlx->x_offset -= 10;
		_clear_draw(mlx);
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		mlx->y_offset += 10;
		_clear_draw(mlx);
	}
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		mlx->y_offset -= 10;
		_clear_draw(mlx);
	}
	if (keydata.key == MLX_KEY_P && keydata.action == MLX_PRESS)
	{
		mlx->projection += 1;
		_clear_draw(mlx);
	}
}

void	scale_and_elev(struct mlx_key_data keydata, t_mlx *mlx)
{
	if (keydata.key == MLX_KEY_E && keydata.action == MLX_PRESS)
	{
		mlx->elevation += 10;
		_clear_draw(mlx);
	}
	if (keydata.key == MLX_KEY_Q && keydata.action == MLX_PRESS)
	{
		mlx->elevation -= 10;
		_clear_draw(mlx);
	}
	if ((keydata.key == MLX_KEY_EQUAL || keydata.key == MLX_KEY_MINUS) 
		&& keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_EQUAL && keydata.action == MLX_PRESS)
			mlx->scale += 1;
		else if (keydata.key == MLX_KEY_MINUS)
		{
			mlx->scale -= 1;
			if (mlx->scale < 1)
				mlx->scale = 1;
		}
		_clear_draw(mlx);
	}
}

void	rotation_keys(struct mlx_key_data keydata, t_mlx *mlx)
{
	if (keydata.key == MLX_KEY_1 && keydata.action == MLX_PRESS)
	{
		mlx->r_z -= 3;
		_clear_draw(mlx);
	}
	if (keydata.key == MLX_KEY_3 && keydata.action == MLX_PRESS)
	{
		mlx->r_z += 3;
		_clear_draw(mlx);
	}
	if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
		mlx->autorotation = !mlx->autorotation;
}

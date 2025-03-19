/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:26:37 by achoukri          #+#    #+#             */
/*   Updated: 2025/03/16 00:20:46 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

void	menu(t_mlx *mlx);

int	main(int ac, char **av)
{
	char			*file;
	int				fd;
	t_mlx			mlx;

	file = av[1];
	check_file(av, ac);
	fd = get_fd(file);
	count_map_size(fd, &mlx);
	allocate_map(&mlx);
	fd = get_fd(file);
	parse_map(fd, &mlx);
	start_mlx(&mlx);
	initialize_view(&mlx);
	menu(&mlx);
	draw_wireframe(&mlx);
	mlx_key_hook(mlx.ptr, key_hooks, &mlx);
	mlx_loop_hook(mlx.ptr, ft_auto_rotation, &mlx);
	mlx_loop(mlx.ptr);
	free_allocated_map(&mlx);
	mlx_delete_texture(mlx.bg_txr);
	mlx_terminate(mlx.ptr);
}

void	start_mlx(t_mlx *mlx)
{
	mlx->ptr = mlx_init(WIDTH, HEIGHT, "FDF", false);
	mlx_ptr_error(mlx->ptr);
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	mlx_img_error(mlx->ptr, mlx->img);
	mlx->bg_txr = mlx_load_png("_bonus/src/r/black.png");
	mlx_txr_error(mlx->bg_txr);
	mlx->bg_img = mlx_texture_to_image(mlx->ptr, mlx->bg_txr);
	mlx_img_error(mlx->ptr, mlx->bg_img);
	mlx_image_to_window(mlx->ptr, mlx->bg_img, 0, 0);
	mlx->win = mlx_image_to_window(mlx->ptr, mlx->img, 0, 0);
}

void	menu(t_mlx *mlx)
{
	mlx_put_string(mlx->ptr, "Usage:", 10, 10);
	mlx_put_string(mlx->ptr, "Change Projection: P", 10, 30);
	mlx_put_string(mlx->ptr, "- Parallel", 30, 50);
	mlx_put_string(mlx->ptr, "- Simple Isometric", 30, 70);
	mlx_put_string(mlx->ptr, "- True Isometric", 30, 90);
	mlx_put_string(mlx->ptr, "", 10, 110);
	mlx_put_string(mlx->ptr, "Move the model:    W A S D", 10, 130);
	mlx_put_string(mlx->ptr, "Change Elevation:  Q E", 10, 150);
	mlx_put_string(mlx->ptr, "Rotate:            1 3", 10, 170);
	mlx_put_string(mlx->ptr, "AutoRotate:        R", 10, 190);
	mlx_put_string(mlx->ptr, "", 10, 210);
	mlx_put_string(mlx->ptr, "Zoom In/Out:       +/-", 10, 230);
	mlx_put_string(mlx->ptr, "Reset View:        T", 10, 250);
	mlx_put_string(mlx->ptr, "Exit:              ESC", 10, 270);
}

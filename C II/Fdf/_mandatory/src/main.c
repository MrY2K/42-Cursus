/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:26:37 by achoukri          #+#    #+#             */
/*   Updated: 2025/03/11 22:02:06 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	initialize_view_elev(t_view_params *view, t_map *map)
{
	float		avg_dim;
	float		k;

	avg_dim = ((float)map->width + (float)map->height) / 2.0f;
	if (avg_dim <= 20)
		k = 10;
	else if (avg_dim <= 40)
		k = 50;
	else if (avg_dim <= 60)
		k = 70;
	else
		k = 100;
	view->elevation = view->scale * (k / avg_dim);
	if (view->elevation < 1)
		view->elevation = 1;
}

void	initialize_view(t_view_params *view, t_map *map)
{
	float		scale_x;
	float		sc_y;
	int			i_center;
	int			j_center;
	t_point2d	center_projected;

	scale_x = (WIDTH * PADING) / ((float)map->width + (float)map->height);
	sc_y = (HEIGHT * PADING) / (((float)map->width + (float)map->height) / 2);
	view->scale = fmin(scale_x, sc_y);
	initialize_view_elev(view, map);
	i_center = map->height / 2;
	j_center = map->width / 2;
	center_projected = project_simple_isometric(i_center, j_center, 0, view);
	view->x_offset = (WIDTH / 2) - center_projected.x;
	view->y_offset = (HEIGHT / 2) - center_projected.y + 100;
}

int	main(int ac, char **av)
{
	char			*file;
	int				fd;
	t_map			map;
	t_mlx			mlx;
	t_view_params	view;

	file = av[1];
	check_file(av, ac);
	fd = get_fd(file);
	count_map_size(fd, &map);
	allocate_map(&map);
	fd = get_fd(file);
	parse_map(fd, &map);
	mlx.ptr = mlx_init(WIDTH, HEIGHT, "FDF", true);
	mlx_ptr_error(mlx.ptr);
	mlx.img = mlx_new_image(mlx.ptr, WIDTH, HEIGHT);
	mlx_img_error(mlx.ptr, mlx.img);
	mlx.win = mlx_image_to_window(mlx.ptr, mlx.img, 0, 0);
	initialize_view(&view, &map);
	draw_wireframe(&map, &mlx, &view);
	mlx_key_hook(mlx.ptr, esc_key_hook, mlx.ptr);
	mlx_loop(mlx.ptr);
	free_allocated_map(&map);
	mlx_terminate(mlx.ptr);
}

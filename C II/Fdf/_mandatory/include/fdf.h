/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 20:58:30 by achoukri          #+#    #+#             */
/*   Updated: 2025/03/16 20:05:16 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// to endicate the behavier of function that check for somthing
# define SUCCESS 1
# define FAILURE 0

// Colors
# define COLOR_WHITE    0xFFFFFFFF  // Opaque white
# define DEFAULT_COLOR  COLOR_WHITE
# define COLOR_RED      COLOR_WHITE //0xFF0000FF  // Opaque red
# define COLOR_BLUE		0x0000FF
# define GREEN          50          //added this here just for the norm

//PROJECTION
# define PROJECTION "true isometric"

# define WIDTH 1800
# define HEIGHT 1200
# define PADING 0.8

# include "../src/get_next_line/get_next_line.h"	// for gnl
# include "../src/libft/libft.h" 					// for libft funcs
# include "../../MLX/include/MLX42/MLX42.h" 	   // for mlx funcs
// # include <MLX42/MLX42.h> 							// for mlx funcs
# include <string.h> 								// for streeror
# include <stdio.h> 								// for perror
# include <stdlib.h> 								// for exit
# include <fcntl.h> 								// for open
# include <unistd.h> 								// for close
# include <math.h> 								    // for cos and sin and M_PI

// The Map point
typedef struct s_point
{
	int	z;
	int	color;
}	t_point;

// The Screen point
typedef struct s_point2d
{
	int	x;
	int	y;
}	t_point2d;

// Map Structures
typedef struct s_map 
{
	t_point	**grid;
	int		width;
	int		height;
	int		z_min;
	int		z_max;
}	t_map;

// mlx
typedef struct s_mlx
{
	mlx_t		*ptr;
	mlx_image_t	*img;
	int			win;
}	t_mlx;

// View
typedef struct s_view_params
{
	int	scale;
	int	elevation;
	int	x_offset;
	int	y_offset;
}	t_view_params;

// Lines params
typedef struct s_line_params
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	float	dx;
	float	dy;
	int		sx;
	int		sy;
	bool	steep;
	float	err;
}	t_line_params;

// Input handling
void		check_file(char **av, int ac);
int			check_file_extension(const char *filename);
int			check_file_exist(const char *filename);
int			get_fd(char *filename);
void		ft_error(char *err_msg);

// Input parsing
void		parse_map(int fd, t_map *map);
void		parse_token(char *token, t_point *point, t_map *map);
void		count_map_size(int fd, t_map *map);
void		allocate_map(t_map *map);

// Utils
int			hex_to_int(const char *hex);
int			ft_atoi_base(const char *str, int str_base);
int			ft_isvalid(char c, int base);
// void		intitilize_view(t_view_params *view);
void		ft_swap(int *a, int *b);

// Error & Free
void		ft_error(char *err_msg);
void		mlx_ptr_error(mlx_t *ptr);
void		mlx_img_error(mlx_t *ptr, mlx_image_t *img);
void		ft_free_split(char **split);
void		free_allocated_map(t_map *map);
void		cleanup_and_exit(char *line, char **tokens, t_map *map, char *msg);
// Bresenham:
void		bresenham(t_point2d st, t_point2d end, mlx_image_t *img, int col);

// Drawing:
void		draw_a_pixel(int x, int y, mlx_image_t *img, int color);
void		draw_wireframe(t_map *map, t_mlx *mlx, t_view_params *v);
// Color
int			get_color(int z, t_map *map);

//Key
void		esc_key_hook(struct mlx_key_data keydata, void *param);

//Project
t_point2d	proj_disp(int i, int j, int z, t_view_params *view);
t_point2d	project_simple_isometric(int i, int j, int z, t_view_params *view);

#endif
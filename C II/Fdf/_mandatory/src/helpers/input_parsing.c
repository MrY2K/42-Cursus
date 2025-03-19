/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:35:54 by achoukri          #+#    #+#             */
/*   Updated: 2025/03/16 23:00:45 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	this file has the funcs that parse the .fdf file/map data 
	and pus them in a structured place to work with them
*/

#include "../../include/fdf.h"

void	parse_map(int fd, t_map *map);
void	parse_token(char *token, t_point *point, t_map *map);
void	count_map_size(int fd, t_map *map);
void	allocate_map(t_map *map);

void	parse_token(char *token, t_point *point, t_map *map)
{
	char	**parts;

	parts = ft_split(token, ',');
	if (!parts || !parts[0])
	{
		ft_free_split(parts); 
	}
	point->z = ft_atoi(parts[0]);
	if (point->z < map->z_min)
		map->z_min = point->z;
	if (point->z > map->z_max)
		map->z_max = point->z;
	if (parts[1])
		point->color = (hex_to_int(parts[1]) << 8) | 0xFF;
	else
		point->color = get_color(point->z, map);
	ft_free_split(parts);
}

void	parse_map(int fd, t_map *map)
{
	char	*line;
	char	**tokens;
	int		token_count;
	int		row;
	int		col;

	row = 0;
	line = get_next_line(fd);
	while (line && row < map->height)
	{
		tokens = ft_split(line, ' ');
		if (!tokens)
			cleanup_and_exit(line, NULL, map, "Split failed");
		free(line);
		token_count = 0;
		while (tokens[token_count]) 
			token_count++;
		col = -1;
		while (++col < map->width)
			parse_token(tokens[col], &map->grid[row][col], map);
		ft_free_split(tokens);
		line = get_next_line(fd);
		row++;
	}
	close(fd);
}

int	valitade_line_width(char *line, t_map *map)
{
	char	**split;
	int		width;

	width = 0;
	split = ft_split(line, ' ');
	while (split[width])
		width++;
	if (map->height == 0)
	{
		map->width = width;
	}
	else if (width < map->width)
	{
		ft_free_split(split);
		return (FAILURE);
	}
	ft_free_split(split);
	return (SUCCESS);
}

void	count_map_size(int fd, t_map *map)
{
	char	*line;
	char	*search;

	map->height = 0;
	map->width = 0;
	map->z_max = INT_MIN;
	map->z_min = INT_MAX;
	line = get_next_line(fd);
	if (!line)
		ft_error("no data");
	while (line)
	{
		search = ft_strchr(line, '\n');
		if (search)
			*search = ' ';
		if (!valitade_line_width(line, map)) 
		{
			free(line);
			ft_error("inconsistent map width");
		}
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	allocate_map(t_map *map)
{
	int	i;

	map->grid = malloc(sizeof(t_point *) * map->height);
	if (!map->grid)
	{
		ft_error("Error allocating map rows");
	}
	i = 0;
	while (i < map->height)
	{
		map->grid[i] = malloc(sizeof(t_point) * map->width);
		if (!map->grid[i])
		{
			while (i-- > 0)
				free(map->grid[i]);
			free(map->grid);
			ft_error("Error allocating map rows");
		}
		i++;
	}
}

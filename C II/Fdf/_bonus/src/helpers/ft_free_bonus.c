/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:03:15 by achoukri          #+#    #+#             */
/*   Updated: 2025/03/15 02:29:57 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf_bonus.h"

void	ft_free_split(char **split);
void	free_allocated_map(t_mlx *map);
void	cleanup_and_exit(char *line, char **tokens, t_mlx *map, char *msg);

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_allocated_map(t_mlx *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
}

void	cleanup_and_exit(char *line, char **tokens, t_mlx *map, char *msg)
{
	if (line) 
		free(line);
	if (tokens) 
		ft_free_split(tokens);
	free_allocated_map(map);
	ft_error(msg);
}

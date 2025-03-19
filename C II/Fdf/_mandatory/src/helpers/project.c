/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 02:03:45 by achoukri          #+#    #+#             */
/*   Updated: 2025/03/11 01:14:34 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

t_point2d	proj_disp(int i, int j, int z, t_view_params *view)
{
	return (project_simple_isometric(i, j, z, view));
}

double	to_radians(double degrees)
{
	return (degrees * (M_PI / 180.0));
}

t_point2d	project_simple_isometric(int i, int j, int z, t_view_params *view)
{
	t_point2d	pt;

	pt.x = (j - i) * view->scale + view->x_offset;
	pt.y = (j + i) * view->scale / 2 - z * view->elevation + view->y_offset;
	return (pt);
}

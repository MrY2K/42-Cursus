/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 20:02:59 by achoukri          #+#    #+#             */
/*   Updated: 2025/03/11 01:10:53 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// FUNCTIONS THAT HANDLES ERRORS:

#include "../../include/fdf.h"

void	ft_error(char *err_msg)
{
	perror(err_msg);
	exit(EXIT_FAILURE);
}

void	mlx_ptr_error(mlx_t *ptr)
{
	if (ptr == NULL)
	{
		mlx_terminate(ptr);
		ft_error("mlx.ptr poiners no good!");
	}
}

void	mlx_img_error(mlx_t *ptr, mlx_image_t *img)
{
	if (img == NULL)
	{
		mlx_delete_image(ptr, img);
		ft_error("mlx.img poiners no good!");
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 03:54:14 by anoteris          #+#    #+#             */
/*   Updated: 2025/02/05 07:06:30 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_parsing(t_parsing *parsing)
{
	int	i ;

	if (parsing->map)
	{
		i = 0 ;
		while (parsing->map[i])
		{
			free(parsing->map[i]);
			i++ ;
		}
		free(parsing->map);
	}
	free(parsing->no_path);
	free(parsing->so_path);
	free(parsing->we_path);
	free(parsing->ea_path);
	if (parsing->pos)
		free(parsing->pos);
	free(parsing);
}

// TODO: Add everything
void	free_raycast(t_raycast *raycast)
{
	free(raycast->pos);
	free(raycast->dir);
	free(raycast->plane);
	free(raycast->rayDir);
	free(raycast->map);
	free(raycast->deltaDist);
	free(raycast->sideDist);
	free(raycast->step);
	free(raycast);
}
void	free_cub3d(t_cub3d *cub3d)
{
	int	i ;

	i = 0 ;
	while (cub3d->map[i])
	{
		free(cub3d->map[i]);
		i++ ;
	}
	free(cub3d->map);
	if (cub3d->images[NO])
		mlx_delete_image(cub3d->mlx, cub3d->images[NO]);
	if (cub3d->images[SO])
		mlx_delete_image(cub3d->mlx, cub3d->images[SO]);
	if (cub3d->images[WE])
		mlx_delete_image(cub3d->mlx, cub3d->images[WE]);
	if (cub3d->images[EA])
		mlx_delete_image(cub3d->mlx, cub3d->images[EA]);
	// if (cub3d->images[DO])
	// 	mlx_delete_image(cub3d->mlx, cub3d->images[DO]);
	free(cub3d->images);
	free_raycast(cub3d->raycast);
	free(cub3d);
}

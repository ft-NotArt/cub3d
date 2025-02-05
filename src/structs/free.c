/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 03:54:14 by anoteris          #+#    #+#             */
/*   Updated: 2025/02/05 16:55:51 by anoteris         ###   ########.fr       */
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
	i = 0 ;
	while (parsing->txtr_paths[i])
	{
		free(parsing->txtr_paths[i]);
		i++ ;
	}
	free(parsing->txtr_paths);
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
	free(raycast->floor);
	free(raycast->tex);
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
	i = 0 ;
	while (cub3d->txtrs[i])
	{
		if (cub3d->txtrs[i])
			mlx_delete_image(cub3d->mlx, cub3d->txtrs[i]);
		i++ ;
	}
	free(cub3d->txtrs);
	free_raycast(cub3d->raycast);
	free(cub3d);
}

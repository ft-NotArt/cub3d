/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 03:54:14 by anoteris          #+#    #+#             */
/*   Updated: 2025/02/09 02:40:44 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_parsing(t_parsing *parsing)
{
	int	i ;

	if (parsing->map)
	{
		i = -1 ;
		while (parsing->map[++i])
			free(parsing->map[i]);
		free(parsing->map);
	}
	i = -1 ;
	while (++i < NB_TXTRS)
		if (parsing->paths[i])
			free(parsing->paths[i]);
	free(parsing->paths);
	if (parsing->map_in_line)
		free(parsing->map_in_line);
	if (parsing->pos)
		free(parsing->pos);
	free(parsing);
}

void	free_raycast(t_raycast *raycast)
{
	free(raycast->pos);
	free(raycast->dir);
	free(raycast->plane);
	free(raycast->ray_dir);
	free(raycast->map);
	free(raycast->delta_dist);
	free(raycast->side_dist);
	free(raycast->step);
	free(raycast->floor);
	free(raycast->tex);
	free(raycast);
}

void	free_cub3d(t_cub3d *cub3d)
{
	int	i ;

	i = -1 ;
	while (cub3d->map[++i])
	{
		free(cub3d->map[i]);
	}
	free(cub3d->map);
	i = -1 ;
	while (++i < NB_TXTRS)
		if (cub3d->txtrs[i])
			mlx_delete_image(cub3d->mlx, cub3d->txtrs[i]);
	free(cub3d->txtrs);
	i = -1 ;
	while (++i < NB_FRAMES)
		if (cub3d->frames[i])
			mlx_delete_image(cub3d->mlx, cub3d->frames[i]);
	free(cub3d->frames);
	free_raycast(cub3d->raycast);
	free(cub3d);
}

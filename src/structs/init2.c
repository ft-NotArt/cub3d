/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 00:28:28 by anoteris          #+#    #+#             */
/*   Updated: 2025/03/30 08:11:16 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_point	*point_init(int x, int y)
{
	t_point	*point ;

	point = malloc(sizeof(t_point));
	point->x = x ;
	point->y = y ;
	return (point);
}

t_vector	*vector_init(double x, double y)
{
	t_vector	*point ;

	point = malloc(sizeof(t_vector));
	point->x = x ;
	point->y = y ;
	return (point);
}

static void	dir_and_plane_vector_init(t_raycast *raycast, t_parsing *pars)
{
	if (pars->player_dir == NO)
	{
		raycast->dir = vector_init(0, 1);
		raycast->plane = vector_init(0.66, 0);
	}
	else if (pars->player_dir == SO)
	{
		raycast->dir = vector_init(0, -1);
		raycast->plane = vector_init(-0.66, 0);
	}
	else if (pars->player_dir == EA)
	{
		raycast->dir = vector_init(1, 0);
		raycast->plane = vector_init(0, -0.66);
	}
	else
	{
		raycast->dir = vector_init(-1, 0);
		raycast->plane = vector_init(0, 0.66);
	}
}

t_raycast	*raycast_init(t_parsing *pars)
{
	t_raycast	*raycast ;

	raycast = malloc(sizeof(t_raycast));
	raycast->pos = pars->pos ;
	pars->pos = NULL ;
	dir_and_plane_vector_init(raycast, pars);
	raycast->ray_dir = vector_init(0, 0);
	raycast->delta_dist = vector_init(0, 0);
	raycast->side_dist = vector_init(0, 0);
	raycast->floor = vector_init(0, 0);
	raycast->tex = vector_init(0, 0);
	raycast->map = point_init(0, 0);
	raycast->step = point_init(0, 0);
	raycast->door = false ;
	return (raycast);
}

t_minimap	*minimap_init(t_cub3d *cub3d)
{
	t_minimap	*minimap ;

	minimap = malloc(sizeof(t_minimap));
	minimap->img = mlx_new_image(cub3d->mlx, MINIMAP_SIZE, MINIMAP_SIZE);
	mlx_image_to_window(cub3d->mlx, minimap->img, 25, 25);
	mlx_set_instance_depth(minimap->img->instances, 2);
	minimap->x = 0 ;
	minimap->y = 0 ;
	minimap->play_x = 0 ;
	minimap->play_y = 0 ;
	minimap->angle = 0 ;
	minimap->cos_angle = 0 ;
	minimap->sin_angle = 0 ;
	minimap->radius = MINIMAP_SIZE / 2 ;
	minimap->center = MINIMAP_SIZE / 2 ;
	minimap->map_size = 0 ;
	minimap->rot_x = 0 ;
	minimap->rot_y = 0 ;
	minimap->dist_x = 0 ;
	minimap->dist_y = 0 ;
	return (minimap);
}

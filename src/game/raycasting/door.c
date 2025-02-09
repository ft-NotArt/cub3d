/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:08:07 by anoteris          #+#    #+#             */
/*   Updated: 2025/02/09 02:52:33 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	dda_algo_on_door(t_cub3d *cub3d, t_raycast *raycast, bool AWP)
{
	bool	hit ;

	hit = false ;
	while (!hit)
	{
		if (raycast->side_dist->x < raycast->side_dist->y)
		{
			raycast->side_dist->x += raycast->delta_dist->x;
			raycast->map->x += raycast->step->x;
			raycast->side = WE + (raycast->step->x == 1);
		}
		else
		{
			raycast->side_dist->y += raycast->delta_dist->y;
			raycast->map->y += raycast->step->y;
			raycast->side = NO + (raycast->step->y != 1);
		}
		if (cub3d->map[raycast->map->y][raycast->map->x] == '1'
			|| cub3d->map[raycast->map->y][raycast->map->x] == 'D'
			|| (cub3d->map[raycast->map->y][raycast->map->x] == 'd' && !AWP))
			hit = true ;
	}
	raycast->door = true ;
	if (cub3d->map[raycast->map->y][raycast->map->x] == '1')
		raycast->door = false ;
}

static void	awp_shot(t_cub3d *cub3d)
{
	t_point	*map ;

	map = cub3d->raycast->map ;
	if (cub3d->map[map->y][map->x] == 'D')
		cub3d->map[map->y][map->x] = '0' ;
}

static void	open_or_close_door(t_cub3d *cub3d, t_raycast *raycast)
{
	if (raycast->side == EA || raycast->side == WE)
		raycast->perp_wall_dist = raycast->side_dist->x
			- raycast->delta_dist->x ;
	else
		raycast->perp_wall_dist = raycast->side_dist->y
			- raycast->delta_dist->y ;
	if (raycast->perp_wall_dist < 2)
	{
		if (cub3d->map[raycast->map->y][raycast->map->x] == 'D')
			cub3d->map[raycast->map->y][raycast->map->x] = 'd' ;
		else if (cub3d->map[raycast->map->y][raycast->map->x] == 'd')
			cub3d->map[raycast->map->y][raycast->map->x] = 'D' ;
	}
}

void	raycast_to_door(t_cub3d *cub3d, bool AWP)
{
	t_raycast	*raycast ;

	raycast = cub3d->raycast ;
	raycast->map->x = (int) raycast->pos->x ;
	raycast->map->y = (int) raycast->pos->y ;
	raycast->ray_dir->x = raycast->dir->x;
	raycast->ray_dir->y = -raycast->dir->y;
	calc_delta_dist(raycast);
	calc_step_and_side_dist(raycast);
	dda_algo_on_door(cub3d, raycast, AWP);
	if (AWP)
		awp_shot(cub3d);
	else
		open_or_close_door(cub3d, raycast);
}

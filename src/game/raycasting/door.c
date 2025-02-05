/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:08:07 by anoteris          #+#    #+#             */
/*   Updated: 2025/02/05 20:10:08 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	DDA_algo_on_door(t_cub3d *cub3d, t_raycast *raycast)
{
	bool	hit ;

	hit = false ;
	while (!hit)
	{
		if(raycast->sideDist->x < raycast->sideDist->y)
		{
			raycast->sideDist->x += raycast->deltaDist->x;
			raycast->map->x += raycast->step->x;
			raycast->side = WE + (raycast->step->x == 1);
		}
		else
		{
			raycast->sideDist->y += raycast->deltaDist->y;
			raycast->map->y += raycast->step->y;
			raycast->side = NO + (raycast->step->y != 1);
		}
		if (cub3d->map[raycast->map->y][raycast->map->x] == '1'
			|| cub3d->map[raycast->map->y][raycast->map->x] == 'D'
			|| cub3d->map[raycast->map->y][raycast->map->x] == 'd')
			hit = true ;
	}
	raycast->door = true ;
	if (cub3d->map[raycast->map->y][raycast->map->x] == '1')
		raycast->door = false ;
}

void	raycast_to_door(t_cub3d *cub3d)
{
	t_raycast	*raycast ;

	raycast = cub3d->raycast ;
	raycast->map->x = (int) raycast->pos->x ;
	raycast->map->y = (int) raycast->pos->y ;
	raycast->rayDir->x = raycast->dir->x;
	raycast->rayDir->y = raycast->dir->y;
	calc_deltaDist(raycast);
	calc_step_and_sideDist(raycast);
	DDA_algo_on_door(cub3d, raycast);
	if(raycast->side == EA || raycast->side == WE)
		raycast->perpWallDist = (raycast->sideDist->x - raycast->deltaDist->x);
	else
		raycast->perpWallDist = (raycast->sideDist->y - raycast->deltaDist->y);
	if (raycast->perpWallDist < 2)
	{
		if (cub3d->map[raycast->map->y][raycast->map->x] == 'D')
			cub3d->map[raycast->map->y][raycast->map->x] = 'd' ;
		else if (cub3d->map[raycast->map->y][raycast->map->x] == 'd')
			cub3d->map[raycast->map->y][raycast->map->x] = 'D' ;
	}
	printf(" \t %f \n", raycast->perpWallDist);
	// draw_line(cub3d, raycast, x);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_calc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 05:44:47 by anoteris          #+#    #+#             */
/*   Updated: 2025/02/05 14:25:31 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_deltaDist(t_raycast *raycast)
{
	raycast->deltaDist->x = 1e30 ;
	if (raycast->rayDir->x != 0)
		raycast->deltaDist->x = fabs(1 / raycast->rayDir->x) ;
	raycast->deltaDist->y = 1e30 ;
	if (raycast->rayDir->y != 0)
		raycast->deltaDist->y = fabs(1 / raycast->rayDir->y) ;
}

void	calc_step_and_sideDist(t_raycast *raycast)
{
	if(raycast->rayDir->x < 0)
	{
		raycast->step->x = -1;
		raycast->sideDist->x = (raycast->pos->x - raycast->map->x) *
			raycast->deltaDist->x;
	}
	else
	{
		raycast->step->x = 1;
		raycast->sideDist->x = (raycast->map->x + 1.0 - raycast->pos->x) *
			raycast->deltaDist->x;
	}
	if(raycast->rayDir->y < 0)
	{
		raycast->step->y = -1;
		raycast->sideDist->y = (raycast->pos->y - raycast->map->y) *
			raycast->deltaDist->y;
	}
	else
	{
		raycast->step->y = 1;
		raycast->sideDist->y = (raycast->map->y + 1.0 - raycast->pos->y) *
			raycast->deltaDist->y;
	}
}

void	calc_line(t_raycast *raycast)
{
	raycast->lineHeight = (int) (SCREENHEIGHT / raycast->perpWallDist);
	raycast->drawStart = -raycast->lineHeight / 2 + SCREENHEIGHT / 2;
	if(raycast->drawStart < 0)
		raycast->drawStart = 0;
	raycast->drawEnd = raycast->lineHeight / 2 + SCREENHEIGHT / 2;
	if(raycast->drawEnd >= SCREENHEIGHT)
		raycast->drawEnd = SCREENHEIGHT - 1;
}

int	calc_texX(t_raycast *raycast, mlx_image_t *img)
{
	double		wallX ;
	int			texX ;
	t_txtr_id	side ;

	side = raycast->side ;
	if (side == EA || side == WE)
		wallX = raycast->pos->y + raycast->perpWallDist * raycast->rayDir->y;
	else
		wallX = raycast->pos->x + raycast->perpWallDist * raycast->rayDir->x;
	wallX -= floor((wallX));
	texX = (int) (wallX * (double) img->width);
	if((side == EA || side == WE) && raycast->rayDir->x > 0)
		texX = img->width - texX - 1;
	if((side == NO || side == SO) && raycast->rayDir->y < 0)
		texX = img->width - texX - 1;
	return (texX);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_calc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 05:44:47 by anoteris          #+#    #+#             */
/*   Updated: 2025/02/09 02:49:59 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_delta_dist(t_raycast *raycast)
{
	raycast->delta_dist->x = 1e30 ;
	if (raycast->ray_dir->x != 0)
		raycast->delta_dist->x = fabs(1 / raycast->ray_dir->x);
	raycast->delta_dist->y = 1e30 ;
	if (raycast->ray_dir->y != 0)
		raycast->delta_dist->y = fabs(1 / raycast->ray_dir->y);
}

void	calc_step_and_side_dist(t_raycast *raycast)
{
	if (raycast->ray_dir->x < 0)
	{
		raycast->step->x = -1;
		raycast->side_dist->x = (raycast->pos->x - raycast->map->x)
			* raycast->delta_dist->x;
	}
	else
	{
		raycast->step->x = 1;
		raycast->side_dist->x = (raycast->map->x + 1.0 - raycast->pos->x)
			* raycast->delta_dist->x;
	}
	if (raycast->ray_dir->y < 0)
	{
		raycast->step->y = -1;
		raycast->side_dist->y = (raycast->pos->y - raycast->map->y)
			* raycast->delta_dist->y;
	}
	else
	{
		raycast->step->y = 1;
		raycast->side_dist->y = (raycast->map->y + 1.0 - raycast->pos->y)
			* raycast->delta_dist->y;
	}
}

void	calc_line(t_raycast *raycast)
{
	raycast->line_height = (int)(SCREENHEIGHT / raycast->perp_wall_dist);
	raycast->draw_start = -raycast->line_height / 2 + SCREENHEIGHT / 2;
	if (raycast->draw_start < 0)
		raycast->draw_start = 0;
	raycast->draw_end = raycast->line_height / 2 + SCREENHEIGHT / 2;
	if (raycast->draw_end >= SCREENHEIGHT)
		raycast->draw_end = SCREENHEIGHT - 1;
}

int	calc_tex_x(t_raycast *raycast, mlx_image_t *img)
{
	double		wall_x ;
	int			tex_x ;
	t_txtr_id	side ;

	side = raycast->side ;
	if (side == EA || side == WE)
		wall_x = raycast->pos->y
			+ raycast->perp_wall_dist * raycast->ray_dir->y;
	else
		wall_x = raycast->pos->x
			+ raycast->perp_wall_dist * raycast->ray_dir->x;
	wall_x -= floor((wall_x));
	tex_x = (int)(wall_x * (double) img->width);
	if ((side == EA || side == WE) && raycast->ray_dir->x > 0)
		tex_x = img->width - tex_x - 1;
	if ((side == NO || side == SO) && raycast->ray_dir->y < 0)
		tex_x = img->width - tex_x - 1;
	return (tex_x);
}

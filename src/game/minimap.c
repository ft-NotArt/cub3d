/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:37:21 by anoteris          #+#    #+#             */
/*   Updated: 2025/03/30 09:20:00 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calc_minimap(t_minimap *minimap, t_cub3d *cub3d)
{
	minimap->play_x = cub3d->raycast->pos->x ;
	minimap->play_y = cub3d->raycast->pos->y ;
	minimap->angle = atan2(cub3d->raycast->dir->y, cub3d->raycast->dir->x);
	minimap->cos_angle = cos(minimap->angle);
	minimap->sin_angle = sin(minimap->angle);
	minimap->map_size = fmax(cub3d->map_width, cub3d->map_height);
}

static void	minimap_in_loop_calc(t_minimap *minimap, double map_x, double map_y)
{
	minimap->rot_x = minimap->cos_angle * (map_x - minimap->play_x)
		- minimap->sin_angle * (map_y - minimap->play_y) + minimap->play_x ;
	minimap->rot_y = minimap->sin_angle * (map_x - minimap->play_x)
		+ minimap->cos_angle * (map_y - minimap->play_y) + minimap->play_y ;
	minimap->x = (minimap->rot_y - minimap->play_y) * MINIMAP_SIZE
		/ minimap->map_size + minimap->center ;
	minimap->y = (minimap->rot_x - minimap->play_x) * MINIMAP_SIZE
		/ minimap->map_size + minimap->center ;
	minimap->dist_x = minimap->x - minimap->center ;
	minimap->dist_y = minimap->y - minimap->center ;
}

static uint32_t	get_minimap_color(t_cub3d *cub3d, double map_x, double map_y)
{
	char	map_char ;

	map_char = cub3d->map[(int) map_y][(int) map_x];
	if (map_char == '1')
		return (BLACK);
	else if (map_char == 'D')
		return (BLUE);
	else if (map_char == 'd')
		return (GREEN);
	else if (map_char == '0')
		return (GRAY);
	else
		return (INVIS);
}

void	minimap(t_minimap *minimap, t_cub3d *cub3d)
{
	double		map_x ;
	double		map_y ;

	calc_minimap(minimap, cub3d);
	ft_memset(minimap->img->pixels, 0x00,
		minimap->img->width * minimap->img->height * 4 * sizeof(uint8_t));
	map_y = 0 ;
	while (map_y < cub3d->map_height)
	{
		map_x = 0 ;
		while (map_x < cub3d->map_width)
		{
			minimap_in_loop_calc(minimap, map_x, map_y);
			if ((minimap->dist_x * minimap->dist_x
					+ minimap->dist_y * minimap->dist_y)
				< (minimap->radius * minimap->radius))
				mlx_put_pixel(minimap->img,
					minimap->x, MINIMAP_SIZE - minimap->y,
					get_minimap_color(cub3d, map_x, map_y));
			map_x += 0.02 ;
		}
		map_y += 0.02 ;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:37:21 by anoteris          #+#    #+#             */
/*   Updated: 2025/02/09 02:21:17 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_minimap_background(t_cub3d *cub3d)
{
	ft_memset(cub3d->minimap->pixels, 0x00, cub3d->minimap->width * cub3d->minimap->height * 4 * sizeof(uint8_t));
}

t_minimap	*minimap_init(t_cub3d *cub3d)
{
	t_minimap	*minimap ;

	minimap = malloc(sizeof(t_minimap));
	minimap->x = 0 ;
	minimap->y = 0 ;
	minimap->play_x = cub3d->raycast->pos->x ;
	minimap->play_y = cub3d->raycast->pos->y ;
	minimap->angle = atan2(cub3d->raycast->dir->y, cub3d->raycast->dir->x);
	minimap->radius = MINIMAP_SIZE / 2 ;
	minimap->center = MINIMAP_SIZE / 2 ;
	minimap->map_size = fmax(cub3d->map_width, cub3d->map_height) ;
	minimap->rot_x = 0 ;
	minimap->rot_y = 0 ;
	minimap->dist_x = 0 ;
	minimap->dist_y = 0 ;
	return (minimap);
}

static void	minimap_in_loop_calc(t_minimap *minimap, double map_x, double map_y)
{
	minimap->rot_x = cos(minimap->angle) * (map_x - minimap->play_x)
		- sin(minimap->angle) * (map_y - minimap->play_y) + minimap->play_x ;
	minimap->rot_y = sin(minimap->angle) * (map_x - minimap->play_x)
		+ cos(minimap->angle) * (map_y - minimap->play_y) + minimap->play_y ;
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

	map_char = cub3d->map[(int) map_y][(int) map_x] ;
	if (map_char == '1')
		return (BLACK);
	else if (map_char == 'D')
		return (BLUE);
	else if (map_char == 'd')
		return (GREEN);
	else
		return (GRAY);
}

void	minimap(t_cub3d *cub3d)
{
	t_minimap	*minimap ;
	double	map_x ;
	double	map_y ;

	minimap = minimap_init(cub3d);
	set_minimap_background(cub3d);
	map_y = 0 ;
	while (map_y < cub3d->map_height)
	{
		map_x = 0 ;
		while (map_x < cub3d->map_width)
		{
			minimap_in_loop_calc(minimap, map_x, map_y);
            if ((minimap->dist_x * minimap->dist_x
				+ minimap->dist_y * minimap->dist_y)
				<= (minimap->radius * minimap->radius))
				mlx_put_pixel(cub3d->minimap, minimap->x, MINIMAP_SIZE - minimap->y, get_minimap_color(cub3d, map_x, map_y));
			map_x += 0.02 ;
		}
		map_y += 0.02 ;
	}
}

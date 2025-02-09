/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:37:21 by anoteris          #+#    #+#             */
/*   Updated: 2025/02/09 00:09:24 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	minimap(t_cub3d *cub3d)
{
	double	map_x ;
	double	map_y ;

	ft_memset(cub3d->minimap->pixels, 0x00, cub3d->minimap->width * cub3d->minimap->height * 4 * sizeof(uint8_t));

	double angle = atan2(cub3d->raycast->dir->y, cub3d->raycast->dir->x);

    double player_x = cub3d->raycast->pos->x;
    double player_y = cub3d->raycast->pos->y;

	map_y = 0 ;
	while (map_y < cub3d->map_height)
	{
		map_x = 0 ;
		while (map_x < cub3d->map_width)
		{
			if (cub3d->map[(int) map_y][(int) map_x] == '1')
			{
				double	rotated_x = cos(angle) * (map_x - player_x)
								  - sin(angle) * (map_y - player_y) + player_x;
				double	rotated_y = sin(angle) * (map_x - player_x)
								  + cos(angle) * (map_y - player_y) + player_y;

				double	map_size = fmax(cub3d->map_width, cub3d->map_height);
				int	minimap_x = (rotated_y - player_y) * MINIMAP_SIZE / map_size + MINIMAP_SIZE / 2 ;
				int	minimap_y = (rotated_x - player_x) * MINIMAP_SIZE / map_size + MINIMAP_SIZE / 2 ;


				if (minimap_x >= 0 && minimap_x < MINIMAP_SIZE &&
                    minimap_y > 0 && minimap_y <= MINIMAP_SIZE)
				{
					mlx_put_pixel(cub3d->minimap, minimap_x, MINIMAP_SIZE - minimap_y, 0x000000FF);
				}
			}
			map_x += 0.02 ;
		}
		map_y += 0.02 ;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:37:21 by anoteris          #+#    #+#             */
/*   Updated: 2025/02/08 23:38:55 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	get_radians(t_vector *dir)
// {
//     double	angle ;
//     double	degrees ;

//     degrees = 180 * angle / PI;
//     return ((int) (360 + round(degrees))) % 360;
// }

/*
// Draw minimap
for (int i = 0; i < map_width; i++) {
    for (int j = 0; j < map_height; j++) {
        // Check if this point is a wall (represented by '#')
        if (world_map[i][j] == '#') {
            // Rotate and scale coordinates for minimap
            float rotated_x = cos(player_angle) * (i - player_x) - sin(player_angle) * (j - player_y) + player_x;
            float rotated_y = sin(player_angle) * (i - player_x) + cos(player_angle) * (j - player_y) + player_y;

            // Map the rotated coordinates to minimap coordinates (scale them down)
            int minimap_x = rotated_x * minimap_size / map_width;
            int minimap_y = rotated_y * minimap_size / map_height;

            // Render the rotated position as a wall (e.g., a black square)
            draw_pixel(minimap_x, minimap_y, 0x000000);  // Black color
        }
    }
}
// Draw player position (a smaller circle or dot in the center of the minimap)
int player_minimap_x = player_x * minimap_size / map_width;
int player_minimap_y = player_y * minimap_size / map_height;
draw_circle(player_minimap_x, player_minimap_y, 3, 0xFF0000);  // Red color
*/

void	minimap(t_cub3d *cub3d)
{
	double	map_x ;
	double	map_y ;

	ft_memset(cub3d->minimap->pixels, 0xFF, cub3d->minimap->width * cub3d->minimap->height * 4 * sizeof(uint8_t));

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
				int	minimap_x = (rotated_y - player_y) * MINIMAP_SIZE / cub3d->map_width + MINIMAP_SIZE / 2 ;
				int	minimap_y = (rotated_x - player_x) * MINIMAP_SIZE / cub3d->map_height + MINIMAP_SIZE / 2 ;


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
	
	mlx_put_pixel(cub3d->minimap, MINIMAP_SIZE / 2, MINIMAP_SIZE / 2, 0xFF0000FF);
	mlx_put_pixel(cub3d->minimap, MINIMAP_SIZE / 2, MINIMAP_SIZE / 2 - 1, 0xFF0000FF);
	mlx_put_pixel(cub3d->minimap, MINIMAP_SIZE / 2, MINIMAP_SIZE / 2 - 2, 0xFF0000FF);
	mlx_put_pixel(cub3d->minimap, MINIMAP_SIZE / 2 - 1, MINIMAP_SIZE / 2 - 1, 0xFF0000FF);
	mlx_put_pixel(cub3d->minimap, MINIMAP_SIZE / 2 - 1, MINIMAP_SIZE / 2, 0xFF0000FF);
	mlx_put_pixel(cub3d->minimap, MINIMAP_SIZE / 2 - 1, MINIMAP_SIZE / 2 + 1, 0xFF0000FF);
	mlx_put_pixel(cub3d->minimap, MINIMAP_SIZE / 2 + 1, MINIMAP_SIZE / 2 - 1, 0xFF0000FF);
	mlx_put_pixel(cub3d->minimap, MINIMAP_SIZE / 2 + 1, MINIMAP_SIZE / 2, 0xFF0000FF);
	mlx_put_pixel(cub3d->minimap, MINIMAP_SIZE / 2 + 1, MINIMAP_SIZE / 2 + 1, 0xFF0000FF);
}

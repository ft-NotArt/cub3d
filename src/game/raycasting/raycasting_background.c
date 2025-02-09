/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_background.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:22:59 by anoteris          #+#    #+#             */
/*   Updated: 2025/02/09 02:50:15 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_pixel_background(t_cub3d *cub3d, mlx_image_t *img,
	int x_pos, int y_pos)
{
	uint32_t	color ;
	t_raycast	*raycast ;
	int			pixel_index ;

	raycast = cub3d->raycast ;
	raycast->tex->x = (int)(img->width * (raycast->floor->x
				- (int) raycast->floor->x)) & (img->width - 1);
	raycast->tex->y = (int)(img->height * (raycast->floor->y
				- (int) raycast->floor->y)) & (img->height - 1);
	pixel_index = (img->width * (int) raycast->tex->y * 4)
		+ (int) raycast->tex->x * 4 ;
	color = get_rgba(img->pixels[pixel_index],
			img->pixels[pixel_index + 1],
			img->pixels[pixel_index + 2],
			false);
	mlx_put_pixel(cub3d->screen, x_pos, y_pos, color);
}

void	draw_background(t_cub3d *cub3d, t_raycast *raycast,
	mlx_image_t *floor, mlx_image_t *ceilling)
{
	int			y ;
	int			x ;

	y = (SCREENHEIGHT / 2);
	while (++y < SCREENHEIGHT)
	{
		raycast->ray_dir->x = raycast->dir->x - raycast->plane->x ;
		raycast->ray_dir->y = raycast->dir->y - raycast->plane->y ;
		raycast->row_dist = (0.5 * SCREENHEIGHT) / (y - SCREENHEIGHT / 2);
		raycast->floor->x = raycast->pos->x
			+ raycast->row_dist * raycast->ray_dir->x ;
		raycast->floor->y = -raycast->pos->y
			+ raycast->row_dist * raycast->ray_dir->y ;
		x = -1 ;
		while (++x < SCREENWIDTH)
		{
			draw_pixel_background(cub3d, floor, x, y);
			draw_pixel_background(cub3d, ceilling, x, (SCREENHEIGHT - y - 1));
			raycast->floor->x += raycast->row_dist * (raycast->dir->x
					+ raycast->plane->x - raycast->ray_dir->x) / SCREENWIDTH;
			raycast->floor->y += raycast->row_dist * (raycast->dir->y
					+ raycast->plane->y - raycast->ray_dir->y) / SCREENWIDTH;
		}
	}
}

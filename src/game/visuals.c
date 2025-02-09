/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visuals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:26:53 by anoteris          #+#    #+#             */
/*   Updated: 2025/02/09 01:21:03 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_crosshair(t_cub3d *cub3d)
{
	mlx_image_t	*crosshair ;
	int			i ;

	crosshair = mlx_new_image(cub3d->mlx, 24, 24);
	mlx_image_to_window(cub3d->mlx, crosshair,
		((SCREENWIDTH / 2) - 16), ((SCREENHEIGHT / 2) - 16));
	mlx_set_instance_depth(crosshair->instances, 2);
	i = 0 ;
	while (i < 24)
	{
		if (i != 11 && i != 12)
		{
			mlx_put_pixel(crosshair, 11, i, 0x000000FF);
			mlx_put_pixel(crosshair, 12, i, 0x000000FF);
			mlx_put_pixel(crosshair, i, 11, 0x000000FF);
			mlx_put_pixel(crosshair, i, 12, 0x000000FF);
		}
		i++ ;
	}
}

void	put_awp_anim_to_window(t_cub3d *cub3d)
{
	int	i ;

	i = -1 ;
	while (cub3d->frames[++i])
	{
		mlx_image_to_window(cub3d->mlx, cub3d->frames[i],
			SCREENWIDTH * (1.0 / 4.0),
			SCREENHEIGHT * (1.0 / 3.0));
		mlx_set_instance_depth(cub3d->frames[i]->instances, 4);
		cub3d->frames[i]->enabled = false ;
	}
	cub3d->frames[0]->enabled = true ;
}
void draw_player_cursor(mlx_image_t *img)
{
	int	*points ;

	points = malloc(5 * sizeof(int));
	points[0] = img->width / 2 ;
	points[1] = img->height / 2 - img->width / 3 ;
	points[2] = img->width / 2 - img->width / 3 ;
	points[3] = img->height / 2 + img->width / 3 ;
	points[4] = img->width / 2 + img->width / 3 ;
	double	t ;

	mlx_put_pixel(img, points[0], points[1], 0xFF0000FF);
	mlx_put_pixel(img, points[2], points[3], 0xFF0000FF);
	mlx_put_pixel(img, points[4], points[3], 0xFF0000FF);
	t = 0 ;
	while (t <= 1)
	{
		mlx_put_pixel(img, points[2] + t * (points[0] - points[2]),
			points[3] + t * (points[1] - points[3]), 0xFF0000FF);
		mlx_put_pixel(img, points[4] + t * (points[0] - points[4]),
			points[3] + t * (points[1] - points[3]), 0xFF0000FF);
		mlx_put_pixel(img, points[2] + t * (points[4] - points[2]),
			points[3] + t * (points[3] - points[3]), 0xFF0000FF);
		t += 0.1 ;
	}
	free(points);
}

void	set_player_cursor_minimap(t_cub3d *cub3d)
{
	mlx_image_t	*img ;

	img = mlx_new_image(cub3d->mlx, 10, 10);
	mlx_image_to_window(cub3d->mlx, img,
		20 + (MINIMAP_SIZE / 2), 20 + (MINIMAP_SIZE / 2));
	mlx_set_instance_depth(img->instances, 3);
	draw_player_cursor(img);
}

void	set_visuals(t_cub3d *cub3d)
{
	draw_crosshair(cub3d);
	put_awp_anim_to_window(cub3d);
	mlx_set_mouse_pos(cub3d->mlx, (SCREENWIDTH / 2), (SCREENHEIGHT / 2));
	mlx_set_cursor_mode(cub3d->mlx, MLX_MOUSE_HIDDEN);
	set_player_cursor_minimap(cub3d);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 02:40:26 by anoteris          #+#    #+#             */
/*   Updated: 2025/02/09 02:47:21 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_line_loop(t_cub3d *cub3d, t_raycast *raycast, int x,
	mlx_image_t *img)
{
	uint32_t	color ;
	double		step ;
	int			y ;

	raycast->tex->x = calc_tex_x(raycast, img);
	step = 1.0 * img->height / raycast->line_height;
	raycast->tex->y = (raycast->draw_start
			- SCREENHEIGHT / 2 + raycast->line_height / 2) * step;
	y = raycast->draw_start ;
	while (y < raycast->draw_end)
	{
		color = get_rgba(img->pixels[(img->width * (int) raycast->tex->y * 4)
				+ (int) raycast->tex->x * 4],
				img->pixels[(img->width * (int) raycast->tex->y * 4)
				+ (int) raycast->tex->x * 4 + 1],
				img->pixels[(img->width * (int) raycast->tex->y * 4)
				+ (int) raycast->tex->x * 4 + 2],
				(raycast->side == SO || raycast->side == EA));
		mlx_put_pixel(cub3d->screen, x, y, color);
		raycast->tex->y += step;
		y++ ;
	}
}

static void	draw_line(t_cub3d *cub3d, t_raycast *raycast, int x)
{
	mlx_image_t	*img ;

	if (raycast->side == EA || raycast->side == WE)
		raycast->perp_wall_dist = (raycast->side_dist->x
				- raycast->delta_dist->x);
	else
		raycast->perp_wall_dist = (raycast->side_dist->y
				- raycast->delta_dist->y);
	img = cub3d->txtrs[raycast->side];
	if (raycast->door)
		img = cub3d->txtrs[DO];
	calc_line(raycast);
	draw_line_loop(cub3d, raycast, x, img);
}

static	void	dda_algo(t_cub3d *cub3d, t_raycast *raycast)
{
	while (cub3d->map[raycast->map->y][raycast->map->x] != '1'
		&& cub3d->map[raycast->map->y][raycast->map->x] != 'D')
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
			raycast->side = NO + (raycast->step->y == 1);
		}
	}
	raycast->door = false ;
	if (cub3d->map[raycast->map->y][raycast->map->x] == 'D')
		raycast->door = true ;
}

void	raycasting(t_cub3d *cub3d)
{
	t_raycast	*raycast ;
	double		camera_x ;
	int			x ;

	raycast = cub3d->raycast ;
	draw_background(cub3d, raycast, cub3d->txtrs[FL], cub3d->txtrs[CE]);
	x = 0 ;
	while (x < SCREENWIDTH)
	{
		raycast->map->x = (int) raycast->pos->x ;
		raycast->map->y = (int) raycast->pos->y ;
		camera_x = 2 * x / (double) SCREENWIDTH - 1;
		raycast->ray_dir->x = raycast->dir->x + raycast->plane->x * camera_x;
		raycast->ray_dir->y = -(raycast->dir->y + raycast->plane->y * camera_x);
		calc_delta_dist(raycast);
		calc_step_and_side_dist(raycast);
		dda_algo(cub3d, raycast);
		draw_line(cub3d, raycast, x);
		x++ ;
	}
	minimap(cub3d);
}

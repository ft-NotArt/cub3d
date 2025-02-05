/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 02:40:26 by anoteris          #+#    #+#             */
/*   Updated: 2025/02/05 07:01:23 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_background(mlx_image_t *screen)
{
	int	x ;
	int	y ;

	x = 0 ;
	while (x < SCREENWIDTH)
	{
		y = 0 ;
		while (y < (SCREENHEIGHT / 2))
		{
			mlx_put_pixel(screen, x, y, 0x87CEEBFF);
			y++ ;
		}
		while (y < SCREENHEIGHT)
		{
			mlx_put_pixel(screen, x, y, 0xD3D3D3FF);
			y++ ;
		}
		x++ ;
	}
}

static void	draw_line_loop(t_cub3d *cub3d, t_raycast *raycast, int x,
	mlx_image_t *img)
{
	uint32_t	color ;
	int			texX ;
	double		step ;
	double		texY ;
	int			y ;

	texX = calc_texX(raycast, img);
	step = 1.0 * img->height / raycast->lineHeight;
	texY = (raycast->drawStart - SCREENHEIGHT / 2 + raycast->lineHeight / 2) * step;
	y = raycast->drawStart ;
	while (y < raycast->drawEnd)
	{
		color = get_rgba(img->pixels[(img->width * (int) texY * 4) + texX * 4],
						img->pixels[(img->width * (int) texY * 4) + texX * 4 + 1],
						img->pixels[(img->width * (int) texY * 4) + texX * 4 + 2],
						(raycast->side == SO || raycast->side == EA));
		mlx_put_pixel(cub3d->screen, x, y, color);
		texY += step;
		y++ ;
	}
}

static void	draw_line(t_cub3d *cub3d, t_raycast *raycast, int x)
{
	mlx_image_t	*img ;

	img = cub3d->images[raycast->side];
	if(raycast->side == EA || raycast->side == WE)
		raycast->perpWallDist = (raycast->sideDist->x - raycast->deltaDist->x);
	else
		raycast->perpWallDist = (raycast->sideDist->y - raycast->deltaDist->y);
	calc_line(raycast);
	draw_line_loop(cub3d, raycast, x, img);
}

static	void	DDA_algo(t_cub3d *cub3d, t_raycast *raycast)
{
	while(cub3d->map[raycast->map->y][raycast->map->x] != '1')
	{
		if(raycast->sideDist->x < raycast->sideDist->y)
		{
			raycast->sideDist->x += raycast->deltaDist->x;
			raycast->map->x += raycast->step->x;
			if (raycast->step->x == 1)
				raycast->side = EA;
			else
				raycast->side = WE;
		}
		else
		{
			raycast->sideDist->y += raycast->deltaDist->y;
			raycast->map->y += raycast->step->y;
			if (raycast->step->y == 1)
				raycast->side = NO;
			else
				raycast->side = SO;
		}
	}
}

void	raycasting(t_cub3d *cub3d)
{
	t_raycast	*raycast ;
	double		cameraX ;
	int			x ;

	raycast = cub3d->raycast ;
	draw_background(cub3d->screen);
	x = 0 ;
	while (x < SCREENWIDTH)
	{
		raycast->map->x = (int) raycast->pos->x ;
		raycast->map->y = (int) raycast->pos->y ;
		cameraX = 2 * x / (double) SCREENWIDTH - 1;
		raycast->rayDir->x = raycast->dir->x + raycast->plane->x * cameraX;
		raycast->rayDir->y = raycast->dir->y + raycast->plane->y * cameraX;
		calc_deltaDist(raycast);
		calc_step_and_sideDist(raycast);
		DDA_algo(cub3d, raycast);
		draw_line(cub3d, raycast, x);
		x++ ;
	}
}

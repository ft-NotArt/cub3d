/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visuals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:26:53 by anoteris          #+#    #+#             */
/*   Updated: 2025/02/08 23:05:22 by anoteris         ###   ########.fr       */
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

void	put_AWP_anim_to_window(t_cub3d *cub3d)
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

void	set_visuals(t_cub3d *cub3d)
{
	draw_crosshair(cub3d);
	put_AWP_anim_to_window(cub3d);
	mlx_set_mouse_pos(cub3d->mlx, (SCREENWIDTH / 2), (SCREENHEIGHT / 2));
	mlx_set_cursor_mode(cub3d->mlx, MLX_MOUSE_HIDDEN);
}

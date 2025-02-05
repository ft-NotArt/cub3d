/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:26:53 by anoteris          #+#    #+#             */
/*   Updated: 2025/02/05 17:39:45 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_crosshair(t_cub3d *cub3d)
{
	mlx_image_t	*crosshair ;
	uint32_t	color ;
	int			i ;

	crosshair = mlx_new_image(cub3d->mlx, 24, 24);
	mlx_image_to_window(cub3d->mlx, crosshair,
		((SCREENWIDTH / 2) - 16), ((SCREENHEIGHT / 2) - 16));
	mlx_set_instance_depth(crosshair->instances, 2);
	color = get_rgba(0x00, 0x00, 0x00, false);
	i = 0 ;
	while (i < 24)
	{
		if (i != 11 && i != 12)
		{
			mlx_put_pixel(crosshair, 11, i, color);
			mlx_put_pixel(crosshair, 12, i, color);
			mlx_put_pixel(crosshair, i, 11, color);
			mlx_put_pixel(crosshair, i, 12, color);
		}
		i++ ;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 04:39:22 by anoteris          #+#    #+#             */
/*   Updated: 2025/02/05 14:50:06 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	frame_loop(void *param)
{
	t_cub3d	*cub3d ;

	cub3d = (t_cub3d *) param ;

	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_W))
		move(cub3d, cub3d->raycast->dir->x, cub3d->raycast->dir->y, MOVE_SPEED);
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_S))
		move(cub3d, -cub3d->raycast->dir->x, -cub3d->raycast->dir->y, MOVE_SPEED);
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_D))
		move(cub3d, cub3d->raycast->dir->y, -cub3d->raycast->dir->x, MOVE_SPEED * 0.75);
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_A))
		move(cub3d, -cub3d->raycast->dir->y, cub3d->raycast->dir->x, MOVE_SPEED * 0.75);

	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_RIGHT))
		rotate(cub3d, -ROT_SPEED);
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_LEFT))
		rotate(cub3d, ROT_SPEED);

	raycasting(cub3d);
}

void	keyboard_hook(mlx_key_data_t keydata, void *param)
{
	t_cub3d	*cub3d ;

	cub3d = (t_cub3d *) param ;
	if (keydata.key == MLX_KEY_ESCAPE)
		close_success(cub3d);
	// TODO: Shoot a bullet w/ AWP
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 04:39:22 by anoteris          #+#    #+#             */
/*   Updated: 2025/02/05 16:06:52 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	frame_loop(void *param)
{
	t_cub3d	*cub3d ;

	cub3d = (t_cub3d *) param ;

	int32_t	x ;
	int32_t	y ;
	mlx_get_mouse_pos(cub3d->mlx, &x, &y);
	mlx_set_mouse_pos(cub3d->mlx, (SCREENWIDTH / 2), (SCREENHEIGHT / 2));

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

	if (x - (SCREENWIDTH / 2))
		rotate(cub3d, -ROT_SPEED * (x - (SCREENWIDTH / 2)) * 0.03);

	raycasting(cub3d);
}

void	keyboard_hook(mlx_key_data_t keydata, void *param)
{
	t_cub3d	*cub3d ;

	cub3d = (t_cub3d *) param ;
	if (keydata.key == MLX_KEY_ESCAPE)
		close_success(cub3d);
	// TODO: Shoot a bullet w/ AWP (maybe in loop_hook)
}

void	cursor_hook(double xpos, double ypos, void* param)
{
	t_cub3d	*cub3d ;

	(void) ypos ;
	cub3d = (t_cub3d *) param ;
	rotate(cub3d, -ROT_SPEED * (xpos - (SCREENWIDTH / 2)) * 0.03);
	mlx_set_mouse_pos(cub3d->mlx, (SCREENWIDTH / 2), (SCREENHEIGHT / 2));
}

// TODO: This should be function that can trigger AWP anim
void	mouse_hook(mouse_key_t button, action_t action, modifier_key_t mods,
	void *param)
{
	t_cub3d	*cub3d ;
	int32_t	x ;
	int32_t	y ;

	(void) button ;
	(void) action ;
	(void) mods ;
	cub3d = (t_cub3d *) param ;
	mlx_get_mouse_pos(cub3d->mlx, &x, &y);
	// rotate(cub3d, -ROT_SPEED * (x - (SCREENWIDTH / 2)));
	mlx_set_mouse_pos(cub3d->mlx, (SCREENWIDTH / 2), (SCREENHEIGHT / 2));
}

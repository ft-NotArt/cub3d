/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 04:10:04 by anoteris          #+#    #+#             */
/*   Updated: 2025/02/05 05:49:56 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move(t_cub3d *cub3d, double dir1, double dir2, double move_speed)
{
	t_vector	*pos ;

	pos = cub3d->raycast->pos ;
	if (cub3d->map[(int) pos->y][(int) (pos->x + dir1 * move_speed)] == '0')
		pos->x += dir1 * move_speed;
	if (cub3d->map[(int) (pos->y + dir2 * move_speed)][(int) pos->x] == '0')
		pos->y += dir2 * move_speed;
}

static void	rotate_vector(t_vector *vector, double rot_speed)
{
	double	oldX ;

	oldX = vector->x ;
	vector->x = vector->x * cos(rot_speed) - vector->y * sin(rot_speed);
	vector->y = oldX * sin(rot_speed) + vector->y * cos(rot_speed);
}

void	rotate(t_cub3d *cub3d, double rot_speed)
{
	rotate_vector(cub3d->raycast->dir, rot_speed);
	rotate_vector(cub3d->raycast->plane, rot_speed);
}

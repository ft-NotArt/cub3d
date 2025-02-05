/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 00:28:28 by anoteris          #+#    #+#             */
/*   Updated: 2025/02/05 22:25:38 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_point	*point_init(int x, int y)
{
	t_point	*point ;

	point = malloc(sizeof(t_point));
	point->x = x ;
	point->y = y ;
	return (point);
}

t_vector	*vector_init(double x, double y)
{
	t_vector	*point ;

	point = malloc(sizeof(t_vector));
	point->x = x ;
	point->y = y ;
	return (point);
}

static void	dir_and_plane_vector_init(t_raycast *raycast, t_parsing *pars)
{
	if (pars->dir == NO)
	{
		raycast->dir = vector_init(0, 1);
		raycast->plane = vector_init(0.66, 0);
	}
	else if (pars->dir == SO)
	{
		raycast->dir = vector_init(0, -1);
		raycast->plane = vector_init(-0.66, 0);
	}
	else if (pars->dir == EA)
	{
		raycast->dir = vector_init(1, 0);
		raycast->plane = vector_init(0, -0.66);
	}
	else
	{
		raycast->dir = vector_init(-1, 0);
		raycast->plane = vector_init(0, 0.66);
	}
}

t_raycast	*raycast_init(t_parsing *pars)
{
	t_raycast	*raycast ;

	raycast = malloc(sizeof(t_raycast));
	raycast->pos = pars->pos ;
	pars->pos = NULL ;
	dir_and_plane_vector_init(raycast, pars);
	raycast->rayDir = vector_init(0, 0);
	raycast->deltaDist = vector_init(0, 0);
	raycast->sideDist = vector_init(0, 0);
	raycast->floor = vector_init(0, 0);
	raycast->tex = vector_init(0, 0);
	raycast->map = point_init(0, 0);
	raycast->step = point_init(0, 0);
	raycast->door = false ;
	return (raycast);
}

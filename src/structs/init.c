/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 00:28:28 by anoteris          #+#    #+#             */
/*   Updated: 2025/02/05 07:04:38 by anoteris         ###   ########.fr       */
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

	//x and y start position
	raycast->pos = pars->pos ;
	pars->pos = NULL ;

	//initial direction vector
	dir_and_plane_vector_init(raycast, pars);

	raycast->rayDir = vector_init(0, 0);
	raycast->map = point_init(0, 0);
	raycast->deltaDist = vector_init(0, 0);
	raycast->sideDist = vector_init(0, 0);
	raycast->step = point_init(0, 0);
	return (raycast);
}

t_cub3d	*cub3d_init(t_parsing *pars)
{
	t_cub3d	*cub3d ;

	cub3d = malloc(sizeof(t_cub3d));
	cub3d->images = malloc(sizeof(mlx_image_t *) * 4);
	ft_bzero(cub3d->images, sizeof(mlx_image_t *) * 4);

	cub3d->map = pars->map ;
	pars->map = NULL ;

	cub3d->mlx = mlx_init(SCREENWIDTH, SCREENHEIGHT, "CUB3D", false);
	if (!cub3d->mlx)
	{
		error_mlx();
		free_parsing(pars);
		close_failure(cub3d);
	}


	cub3d->screen = mlx_new_image(cub3d->mlx, SCREENWIDTH, SCREENHEIGHT);

	cub3d->images[NO] = get_mlx_img(cub3d, pars, pars->no_path);
	cub3d->images[SO] = get_mlx_img(cub3d, pars, pars->so_path);
	cub3d->images[WE] = get_mlx_img(cub3d, pars, pars->we_path);
	cub3d->images[EA] = get_mlx_img(cub3d, pars, pars->ea_path);

	cub3d->raycast = raycast_init(pars);

	return (cub3d);
}

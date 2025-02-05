/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 03:58:05 by anoteris          #+#    #+#             */
/*   Updated: 2025/02/05 04:38:09 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	close_cub3d(t_cub3d *cub3d)
{
	mlx_t	*mlx ;

	mlx = cub3d->mlx ;
	free_cub3d(cub3d);
	mlx_close_window(mlx);
	mlx_terminate(mlx);
}

void	close_success(void *param)
{
	t_cub3d	*cub3d ;

	cub3d = (t_cub3d *) param ;
	close_cub3d(cub3d);
	exit(EXIT_SUCCESS);
}

void	close_failure(void *param)
{
	t_cub3d	*cub3d ;

	cub3d = (t_cub3d *) param ;
	close_cub3d(cub3d);
	exit(EXIT_FAILURE);
}

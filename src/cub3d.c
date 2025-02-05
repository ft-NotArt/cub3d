/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:32:25 by kaveo             #+#    #+#             */
/*   Updated: 2025/02/05 05:53:37 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main()
{

	t_parsing	*pars = malloc(sizeof(t_parsing));

	pars->map = malloc(sizeof(char *) * 9);

	pars->map[0] = ft_strdup("11111111");
	pars->map[1] = ft_strdup("10000001");
	pars->map[2] = ft_strdup("10000001");
	pars->map[3] = ft_strdup("10000001");
	pars->map[4] = ft_strdup("10000001");
	pars->map[5] = ft_strdup("10000001");
	pars->map[6] = ft_strdup("10000001");
	pars->map[7] = ft_strdup("11111111");
	pars->map[8] = NULL ;

	pars->no_path = ft_strdup("textures/soinc.png") ;
	pars->so_path = ft_strdup("textures/brick.png") ;
	pars->ea_path = ft_strdup("textures/vroum.png") ;
	pars->we_path = ft_strdup("textures/TUX.png") ;

	pars->pos = vector_init(4, 4);

	pars->dir = NO ;






	t_cub3d	*cub3d ;

	cub3d = cub3d_init(pars);
	free_parsing(pars);


	mlx_image_to_window(cub3d->mlx, cub3d->screen, 0, 0);

	mlx_loop_hook(cub3d->mlx, frame_loop, cub3d);
	mlx_key_hook(cub3d->mlx, keyboard_hook, cub3d);
	mlx_close_hook(cub3d->mlx, close_success, cub3d);

	mlx_loop(cub3d->mlx);
}

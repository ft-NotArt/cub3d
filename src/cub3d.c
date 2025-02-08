/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:32:25 by kaveo             #+#    #+#             */
/*   Updated: 2025/02/08 19:50:09 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main()
{

	t_parsing	*pars = malloc(sizeof(t_parsing));

	pars->map = malloc(sizeof(char *) * 9);

	pars->map[0] = ft_strdup("11111111");
	pars->map[1] = ft_strdup("1DDDDDD1");
	pars->map[2] = ft_strdup("100000D1");
	pars->map[3] = ft_strdup("100000D1");
	pars->map[4] = ft_strdup("100000D1");
	pars->map[5] = ft_strdup("100000D1");
	pars->map[6] = ft_strdup("100000D1");
	pars->map[7] = ft_strdup("11111111");
	pars->map[8] = NULL ;

	pars->txtr_paths = malloc(sizeof(char *) * 8);

	pars->txtr_paths[NO] = ft_strdup("textures/soinc.png") ;
	pars->txtr_paths[SO] = ft_strdup("textures/brick.png") ;
	pars->txtr_paths[WE] = ft_strdup("textures/vroum.png") ;
	pars->txtr_paths[EA] = ft_strdup("textures/TUX.png") ;
	pars->txtr_paths[DO] = ft_strdup("textures/door.png") ;
	pars->txtr_paths[FL] = ft_strdup("textures/floor.png") ;
	pars->txtr_paths[CE] = ft_strdup("textures/shitty_ceilling.png") ;
	pars->txtr_paths[7] = NULL ;

	pars->pos = vector_init(4, 4);

	pars->dir = NO ;






	t_cub3d	*cub3d ;

	cub3d = cub3d_init(pars);
	free_parsing(pars);



	draw_crosshair(cub3d);
	put_AWP_anim_to_window(cub3d);


	mlx_set_mouse_pos(cub3d->mlx, (SCREENWIDTH / 2), (SCREENHEIGHT / 2));
	mlx_set_cursor_mode(cub3d->mlx, MLX_MOUSE_HIDDEN);

	mlx_loop_hook(cub3d->mlx, frame_loop, cub3d);
	mlx_key_hook(cub3d->mlx, keyboard_hook, cub3d);
	mlx_mouse_hook(cub3d->mlx, mouse_hook, cub3d);
	mlx_close_hook(cub3d->mlx, close_success, cub3d);

	mlx_loop(cub3d->mlx);
}

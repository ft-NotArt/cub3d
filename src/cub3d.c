/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:45:08 by anoteris          #+#    #+#             */
/*   Updated: 2025/02/09 04:16:12 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	launch_cub3d(t_parsing *pars)
{
	t_cub3d	*cub3d ;

	cub3d = cub3d_init(pars);
	free_parsing(pars);
	set_visuals(cub3d);
	mlx_loop_hook(cub3d->mlx, frame_loop, cub3d);
	mlx_key_hook(cub3d->mlx, keyboard_hook, cub3d);
	mlx_mouse_hook(cub3d->mlx, mouse_hook, cub3d);
	mlx_close_hook(cub3d->mlx, close_success, cub3d);
	mlx_loop(cub3d->mlx);
}

int	main(int ac, char **av)
{
	t_parsing	*parsing;

	if (!args_checker(ac, av))
		exit(1);
	parsing = init_parsing();
	if (!is_valid_map(av[1], parsing))
		return (free_parsing(parsing), 1);
	launch_cub3d(parsing);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:45:48 by kaveo             #+#    #+#             */
/*   Updated: 2025/02/07 18:32:25 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_paths(t_parsing *parsing)
{
	int i = 0;
	while (i < 7)
	{
		if (!parsing->paths[i])
		{
			return (false);
		}
		i++;
	}
	return (true);
}

int main(int ac, char **av)
{
	t_parsing	*parsing;

	if (!args_checker(ac, av))
		exit(1);
	parsing = init_parsing(av[1]);
	// print_map(parsing->map);
	printf("%d\n", parsing->player_dir);
	printf("%d\n", parsing->player_x);
	printf("%d\n", parsing->player_y);
	printf("%c\n", parsing->map[11][26]);
	// printf("%d\n", parsing->map_height);
	// print_paths(parsing);
	// if (!check_paths(parsing))
	// {
	// 	ft_printf_fd(2, "Paths are missing !\n");
	// 	exit(1);
	// }
	// is_playable_map(parsing);
	free_parsing(parsing);
}

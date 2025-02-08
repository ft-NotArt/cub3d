/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:45:48 by kaveo             #+#    #+#             */
/*   Updated: 2025/02/08 05:43:42 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_parsing	*init_parsing()
{
	t_parsing	*parsing;

	parsing = malloc(sizeof(t_parsing));
	parsing->paths = malloc(sizeof(char *) * (PATHS_COUNT + 1));
	ft_bzero(parsing->paths, (PATHS_COUNT + 1) * sizeof(char *));
	parsing->map = NULL;
	parsing->map_in_line = NULL;
	parsing->map_height = 0;
	parsing->map_width = 0;
	parsing->player_x = 0;
	parsing->player_y = 0;
	parsing->player_dir = 0;
	return (parsing);
}

int main(int ac, char **av)
{
	t_parsing	*parsing;

	if (!args_checker(ac, av))
		exit(1);
	parsing = init_parsing();
	if (!is_valid_map(av[1], parsing))
		return (free_parsing(parsing), 1);
	// print_paths(parsing);
	// print_map(parsing->map);
	free_parsing(parsing);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:45:48 by kaveo             #+#    #+#             */
/*   Updated: 2025/02/08 20:00:12 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_parsing	*init_parsing(void)
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

int	handle_open(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror(filename);
		return (-1);
	}
	return (fd);
}

int	main(int ac, char **av)
{
	t_parsing	*parsing;

	if (!args_checker(ac, av))
		exit(1);
	parsing = init_parsing();
	if (!is_valid_map(av[1], parsing))
		return (free_parsing(parsing), 1);
	free_parsing(parsing);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:45:48 by kaveo             #+#    #+#             */
/*   Updated: 2025/02/06 17:06:52 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_parsing	*init_parsing(char *filename)
{
	t_parsing	*parsing;

	(void) filename;
	parsing = malloc(sizeof(t_parsing));
	if (!parsing)
		return (NULL);
	parsing->paths = malloc(sizeof(char *) * 8);
	ft_bzero(parsing->paths, 8 * sizeof(char *));
	parsing->map_height = 0;
	parsing->player_x = 0;
	parsing->player_y = 0;
	parsing->map = NULL;
	return (parsing);
}

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
	(void) parsing;
	parsing->map = get_map_data(av[1], parsing);
	print_paths(parsing);
	if (!check_paths(parsing))
	{
		ft_printf_fd(2, "Paths are missing !\n");
		exit(1);
	}
	is_playable_map(parsing);
	free_parsing(parsing);
}

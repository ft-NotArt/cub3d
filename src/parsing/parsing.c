/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:45:48 by kaveo             #+#    #+#             */
/*   Updated: 2025/02/05 11:13:32 by kaveo            ###   ########.fr       */
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
	parsing->paths = malloc(8 * sizeof(char *));
	// ft_bzero(parsing->paths)
	// parsing->map = get_map(filename);
	parsing->map = NULL; // TODO change later
	return (parsing);
}

int main(int ac, char **av)
{
	t_parsing	*parsing;

	if (!args_checker(ac, av))
		exit(1);
	parsing = init_parsing(av[1]);
	(void) parsing;
	get_map_data(av[1], parsing);
	print_paths(parsing);
	free(parsing);
}

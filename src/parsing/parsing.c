/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:45:48 by kaveo             #+#    #+#             */
/*   Updated: 2025/02/04 21:07:06 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_parsing	*init_parsing_struct(char *filename)
{
	t_parsing	*parsing;

	(void) filename;
	parsing = malloc(sizeof(t_parsing));
	if (!parsing)
		return (NULL);
	parsing->ea_path = NULL;
	parsing->no_path = NULL;
	parsing->so_path = NULL;
	parsing->we_path = NULL;
	// parsing->map = get_map(filename);
	parsing->map = NULL; // TODO change later
	return (parsing);
}


int main(int ac, char **av)
{
	t_parsing	*parsing;

	if (!args_checker(ac, av))
		exit(1);
	parsing = init_parsing_struct(av[1]);
	(void) parsing;
	get_map(av[1], parsing);
	free(parsing);
}

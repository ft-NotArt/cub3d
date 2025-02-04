/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:35:23 by kaveo             #+#    #+#             */
/*   Updated: 2025/02/04 22:50:19 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

void	print_paths(t_parsing *parsing)
{
	printf("%s\n", parsing->no_path);
	printf("%s\n", parsing->so_path);
	printf("%s\n", parsing->we_path);
	printf("%s\n", parsing->ea_path);
}

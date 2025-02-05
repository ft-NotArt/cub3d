/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:35:23 by kaveo             #+#    #+#             */
/*   Updated: 2025/02/05 11:04:50 by kaveo            ###   ########.fr       */
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
	printf("%s\n", parsing->paths[NO]);
	printf("%s\n", parsing->paths[SO]);
	printf("%s\n", parsing->paths[WE]);
	printf("%s\n", parsing->paths[EA]);
	printf("%s\n", parsing->paths[DO]);
	printf("%s\n", parsing->paths[FL]);
	printf("%s\n", parsing->paths[CE]);
}

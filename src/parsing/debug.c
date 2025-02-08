/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:35:23 by kaveo             #+#    #+#             */
/*   Updated: 2025/02/08 00:29:03 by albillie         ###   ########.fr       */
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
	int	i;

	i = 0;
	while (parsing->paths[i])
	{
		printf("%s\n", parsing->paths[i]);
		i++;
	}
}

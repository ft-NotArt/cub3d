/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 23:32:29 by albillie          #+#    #+#             */
/*   Updated: 2025/02/08 05:30:39 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	flood_fill(char **map, int y, int x, int height)
{

	if ((x == -1 || y == -1) || (y == (height - 1) && map[x][y] == '0'))
	{
		ft_printf_fd(2, "Error\nMap is not closed\n");
		return ;
	}
	if (map[y][x] == ' ' || map[y][x] == '\n')
	{
		ft_printf_fd(2, "Error\nMap is not closed\n");
		return ;
	}
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill(map, y - 1, x, height);
	flood_fill(map, y + 1, x, height);
	flood_fill(map, y, x - 1, height);
	flood_fill(map, y, x + 1, height);
}

char	**create_floodfill_map(t_parsing *parsing)
{
	char	**map;
	int 	y;
	size_t 	x;

	map = malloc(sizeof(char **) * (parsing->map_height + 1));
	y = 0;
	while (parsing->map[y])
	{
		x = 0;
		map[y] = malloc(sizeof(char *) * (get_higher_line_len(parsing->map) + 2));
		ft_strlcpy(map[y], parsing->map[y], ft_strlen(parsing->map[y]) + 1);
		while (map[y][x])
			x++;
		while (x < get_higher_line_len(parsing->map))
		{
			map[y][x] = ' ';
			x++;
		}
		map[y][x] = '\n';
		map[y][x + 1] = '\0';
		y++;
	}
	map[y] = NULL;
	return (map);
}

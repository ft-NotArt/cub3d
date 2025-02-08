/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 23:32:29 by albillie          #+#    #+#             */
/*   Updated: 2025/02/08 20:02:59 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	flood_fill(char **map, int y, int x, t_parsing *parsing)
{
	if ((x == -1 || y == -1) || (y == (parsing->map_height - 1)
			&& map[y][x] == '0'))
	{
		ft_printf_fd(2, "Error\nMap is not closed\n");
		free_parsing(parsing);
		free_str_array(map);
		exit(1);
	}
	if (map[y][x] == ' ' || map[y][x] == '\n')
	{
		ft_printf_fd(2, "Error\nMap is not closed\n");
		free_parsing(parsing);
		free_str_array(map);
		exit(1);
	}
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill(map, y - 1, x, parsing);
	flood_fill(map, y + 1, x, parsing);
	flood_fill(map, y, x - 1, parsing);
	flood_fill(map, y, x + 1, parsing);
}

char	**create_floodfill_map(t_parsing *parsing)
{
	char	**map;
	int		y;
	size_t	x;

	map = malloc(sizeof(char **) * (parsing->map_height + 1));
	y = 0;
	while (parsing->map[y])
	{
		x = 0;
		map[y] = malloc(sizeof(char *) * (get_higher_len(parsing->map) + 2));
		ft_strlcpy(map[y], parsing->map[y], ft_strlen(parsing->map[y]) + 1);
		while (map[y][x])
			x++;
		while (x < get_higher_len(parsing->map))
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

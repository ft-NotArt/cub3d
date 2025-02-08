/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 23:32:29 by albillie          #+#    #+#             */
/*   Updated: 2025/02/07 23:37:30 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	flood_fill(char **map, int x, int y, int height)
{
	if ((x == -1 || y == -1) || (x == (height - 1) && map[x][y] == '0'))
	{
		ft_printf_fd(2, "Error\nMap is not closed\n");
		exit(1);
	}
	if (map[x][y] == ' ' || map[x][y] == '\n')
	{
		printf("Map is not closed\n");
		exit(1);
	}
	if (map[x][y] == '1' || map[x][y] == 'V')
		return ;
	map[x][y] = 'V';
	flood_fill(map, x - 1, y, height);
	flood_fill(map, x + 1, y, height);
	flood_fill(map, x, y - 1, height);
	flood_fill(map, x, y + 1, height);
}

char	**create_floodfill_map(t_parsing *parsing)
{
	char	**map;
	int 	i;
	size_t 	j;

	map = malloc(sizeof(char **) * (parsing->map_height + 1));
	i = 0;
	while (parsing->map[i])
	{
		j = 0;
		map[i] = malloc(sizeof(char *) * (get_higher_line_len(parsing->map) + 2));
		ft_strlcpy(map[i], parsing->map[i], ft_strlen(parsing->map[i]) + 1);
		while (map[i][j])
			j++;
		while (j < get_higher_line_len(parsing->map))
		{
			map[i][j] = ' ';
			j++;
		}
		map[i][j] = '\n';
		map[i][j + 1] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

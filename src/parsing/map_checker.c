/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:25:18 by kaveo             #+#    #+#             */
/*   Updated: 2025/02/03 20:17:51 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// TODO free

void	check_for_spaces(char *map)
{
	int i = 0;
	while (map[i] != '\n')
	{
		i++;
	}
	printf("%c\n", map[i - 1]);
	printf("%d\n", i);
}

char	**get_map(char *filename)
{
	int		fd;
	char	**map = NULL;
	char	*line;
	char	*map_in_line;
	char	*temp;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (perror(filename), NULL);
	map_in_line = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		temp = ft_strjoin(map_in_line, line);
		map_in_line = temp;
		line = get_next_line(fd);
	}
	// map = ft_split(map_in_line, '\0');
	// printf("%s", map_in_line);
	// print_map(map);
	printf("%s", map_in_line);
	check_for_spaces(map_in_line);
	return (map);
}

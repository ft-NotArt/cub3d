/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:25:18 by kaveo             #+#    #+#             */
/*   Updated: 2025/02/03 22:17:47 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// TODO free

void	send_lines_to_parsing(char *map_in_line)
{
	int	i;

	i = 0;
	while (ft_isspace(map_in_line[i]))
	{
		i++;
	}
	if (ft_strncmp(map_in_line, "NO", 2) == 0 || ft_strncmp(map_in_line, "SO", 2) == 0 || ft_strncmp(map_in_line, "WE", 2) == 0 || ft_strncmp(map_in_line, "EA", 2) == 0)
	{
		printf("map texture on first line");
	}
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
		if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0 || ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0 || ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0)
		{
			printf("map texture on first line\n");
		}
		else if (line[0] == '\n')
		{
			printf("%s", line);
		}
		else if (is_map_charset(line[0]))
		{
			while (line)
			{
				if (line[0] == '\n')
				{
					printf("Error");
					free(line);
					return NULL;
				}
				printf("%s", line);
				line = get_next_line(fd);
			}
			// printf("%s", line);
		}
		temp = ft_strjoin(map_in_line, line);
		map_in_line = temp;
		line = get_next_line(fd);
	}
	// map = ft_split(map_in_line, '\0');
	// printf("%s", map_in_line);
	// print_map(map);
	printf("%s", map_in_line);
	// send_lines_to_parsing(map_in_line);
	return (map);
}

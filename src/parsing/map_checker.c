/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:25:18 by kaveo             #+#    #+#             */
/*   Updated: 2025/02/04 23:48:47 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// TODO free

char	*get_texture_path(char *line, char c, char c1)
{
	int		i;
	char	*temp;
	char	*path;

	i = 0;
	temp = ft_strtrim(line, " ");
	free(line);
	if (temp[i] != c || temp[i + 1] != c1)
	{
		ft_printf_fd(2, "Error\nInvalid character on %c%c texture line\n",
				c, c1);
		return (NULL);
	}
	i += 2;
	while (temp[i] && ft_isspace(temp[i]))
		i++;
	path = malloc(10000);
	int j = 0;
	while (temp[i] && !ft_isspace(temp[i]))
	{
		path[j] = temp[i];
		i++;
		j++;
	}
	path[j] = '\0';
	return (path);
}

void	parse_by_id(t_id id, t_parsing *parsing, char *line)
{
	if (id == NORTH)
		parsing->no_path = get_texture_path(line, 'N', 'O');
	else if (id == SOUTH)
		parsing->so_path = get_texture_path(line, 'S', 'O');
	else if (id == EAST)
		parsing->we_path = get_texture_path(line, 'E', 'A');
	else if (id == WEST)
		parsing->ea_path = get_texture_path(line, 'W', 'E');
	// else if (id == )
	// 	parsing->no_path = get_texture_path(line, 'C', 'O');
	// else if (id == SOUTH)
	// 	parsing->no_path = get_texture_path(line, 'F', 'O');
}

int	get_identifier_id(char *line)
{
	if (ft_strnstr(line, "NO", ft_strlen(line)))
		return (NORTH);
	else if (ft_strnstr(line, "WE", ft_strlen(line)))
		return (WEST);
	else if (ft_strnstr(line, "SO", ft_strlen(line)))
		return (SOUTH);
	else if (ft_strnstr(line, "EA", ft_strlen(line)))
		return (EAST);
	else if (ft_strnstr(line, "C", ft_strlen(line)))
		return (CEILLING);
	else if (ft_strnstr(line, "F", ft_strlen(line)))
		return (FLOOR);
	return (-1);
}

// void	parse_identifier(char *line, t_parsing *parsing)
// {
// 	if (get_identifier_id(line) == NORTH)
// 	{
// 		parse_by_id(NORTH, parsing, line);
// 	}
// }


void	parse_map(char **map, t_parsing *parsing)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (is_map_identifier(map[i]))
		{
			parse_by_id(get_identifier_id(map[i]), parsing, map[i]);
		}
		else if (map[i][0] == '\n')
		{
		}
		else if (is_map_charset(map[i]))
		{
			while (map[i])
			{
				if (map[i][0] == '\n' || !is_map_charset(map[i]))
				{
					printf("%s\n", map[i]);
					printf("Error\n");
					exit(1);
				}
				i++;
			}
		}
		i++;
	}
}

char	**get_map(char *filename, t_parsing *parsing)
{
	int		fd;
	char	**map = NULL;
	char	*line;
	char	*map_in_line;
	char	*temp;

	(void) parsing;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (perror(filename), NULL);
	map_in_line = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		if (is_map_identifier(line))
		{
			parse_by_id(get_identifier_id(line), parsing, line);
		}
		else if (line[0] == '\n')
		{
		}
		else if (is_map_charset(line))
		{
			while (line)
			{
				if (line[0] == '\n' || !is_map_charset(line))
				{
					printf("Error\n");
					exit(1);
				}
				line = get_next_line(fd);
			}
		}
		else
			temp = ft_strjoin(map_in_line, line);
		map_in_line = temp;
		line = get_next_line(fd);
	}
	map = ft_split(map_in_line, '\n');
	print_map(map);
	parse_map(map, parsing);
	return (map);
}

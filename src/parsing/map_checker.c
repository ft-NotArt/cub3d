/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:25:18 by kaveo             #+#    #+#             */
/*   Updated: 2025/02/04 21:06:33 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// TODO free

char	*get_texture_path(char *line, int c, int c1)
{
	int		i;
	char	*temp;

	i = 0;
	temp = ft_strtrim(line, " ");
	free(line);
	if (temp[i] != c || temp[i + 1] != c1)
	{
		free(temp);
		return NULL;
	}
	i += 2;
	while (temp[i] && ft_isspace(temp[i]))
		i++;
	while (temp[i] && !ft_isspace(temp[i]))
	{
		printf("%c", temp[i]);
		i++;
	}
	return (NULL);
}

void	parse_by_id(t_id id, t_parsing *parsing, char *line)
{
	if (id == NORTH)
		parsing->no_path = get_texture_path(line, 'N', 'O');
	else if (id == SOUTH)
		parsing->so_path = get_texture_path(line, 'S', 'O');
	else if (id == EAST)
		parsing->we_path = get_texture_path(line, 'E', 'E');
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

char	**get_map(char *filename, t_parsing *parsing)
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
		if (is_map_identifier(line))
		{
			printf("%s", line);
			parse_by_id(get_identifier_id(line), parsing, line);
			free(map_in_line);
			break;
			// parse_identifier(line, parsing);
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
	return (map);
}

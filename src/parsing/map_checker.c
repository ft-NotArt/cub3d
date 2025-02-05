/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:25:18 by kaveo             #+#    #+#             */
/*   Updated: 2025/02/05 21:14:47 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	count_path_words(char *line)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (line[i])
	{
		while (ft_isspace(line[i]))
			i++;
		if (line[i])
			count++;
		while (line[i] && !ft_isspace(line[i]))
			i++;
	}
	if (count != 2)
		return (false);
	return (true);
}

static int	get_path_len(char *temp)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (!ft_isspace(temp[i]))
		i++;
	while (ft_isspace(temp[i]))
		i++;
	while (!ft_isspace(temp[i]))
	{
		i++;
		len++;
	}
	return (len);
}

// static char	*get_trimmed_line(char *line)
// {
// 	char	*temp;

// 	temp = ft_strtrim(line, " ,	");


// 	return (temp);
// }

char	*get_texture_path(char *line, char c, char c1)
{
	int		i;
	int		j;
	char	*temp;
	char	*path;

	if (!count_path_words(line))
	{
		ft_printf_fd(2, "Error\nInvalid words count on %c%c texture line\n", c, c1);
		exit(EXIT_FAILURE);
	}
	temp = ft_strtrim(line, " ,	");
	free(line);
	i = 0;
	if (temp[i] != c || temp[i + 1] != c1)
	{
		ft_printf_fd(2, "Error\nInvalid character on %c%c texture line\n", c, c1);
		exit(1);
	}
	i += 2;
	while (temp[i] && ft_isspace(temp[i]))
		i++;
	path = malloc(sizeof(char *) + (get_path_len(temp)));
	j = 0;
	while (temp[i] && !ft_isspace(temp[i]))
		path[j++] = temp[i++];
	path[j] = '\0';
	free(temp);
	return (path);
}

void	parse_by_id(t_txtr_id id, t_parsing *parsing, char *line)
{
	if (id == NO)
		parsing->paths[NO] = get_texture_path(line, 'N', 'O');
	else if (id == SO)
		parsing->paths[SO] = get_texture_path(line, 'S', 'O');
	else if (id == WE)
		parsing->paths[WE] = get_texture_path(line, 'W', 'E');
	else if (id == EA)
		parsing->paths[EA] = get_texture_path(line, 'E', 'A');
	else if (id == DO)
		parsing->paths[DO] = get_texture_path(line, 'D', 'O');
	else if (id == FL)
		parsing->paths[FL] = get_texture_path(line, 'F', ' ');
	else if (id == CE)
		parsing->paths[CE] = get_texture_path(line, 'C', ' ');
}

int	get_identifier_id(char *line)
{
	if (ft_strnstr(line, "NO", ft_strlen(line)))
		return (NO);
	else if (ft_strnstr(line, "SO", ft_strlen(line)))
		return (SO);
	else if (ft_strnstr(line, "WE", ft_strlen(line)))
		return (WE);
	else if (ft_strnstr(line, "EA", ft_strlen(line)))
		return (EA);
	else if (ft_strnstr(line, "DO", ft_strlen(line)))
		return (DO);
	else if (ft_strnstr(line, "F", ft_strlen(line)))
		return (FL);
	else if (ft_strnstr(line, "C", ft_strlen(line)))
		return (CE);
	return (-1);
}

char	**get_map_data(char *filename, t_parsing *parsing)
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
			parse_by_id(get_identifier_id(line), parsing, line);
		}
		else if (is_map_charset(line))
		{
			while (line)
			{
				temp = ft_strjoin(map_in_line, line);
				map_in_line = temp;
				if (line[0] == '\n' || !is_map_charset(line))
				{
					ft_printf_fd(2, "Error\nNewlines inside the map !\n");
					exit(1);
				}
				free(line);
				line = get_next_line(fd);
			}
		}
		line = get_next_line(fd);
	}
	map = ft_split(map_in_line, '\n');
	return (map);
}

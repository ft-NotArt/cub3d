/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:25:18 by kaveo             #+#    #+#             */
/*   Updated: 2025/02/08 02:05:38 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_valid_map(char *filename, t_parsing *parsing)
{
	if (!get_map_data(filename, parsing))
		return (false);
	return (true);
}

static int	handle_open(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror(filename);
		return (-1);
	}
	return (fd);
}

char	*handle_map(char *map_in_line, char *line)
{
	char	*temp;

	if (line[0] == '\n' || !is_map_charset(line))
	{
		ft_printf_fd(2, "Error\nInvalid characters in the map !\n");
		exit(1);
	}
	temp = ft_strjoin(map_in_line, line);
	map_in_line = temp;
	return (map_in_line);
}

bool	get_map_line(char *line, t_parsing *parsing)
{
	char	*temp;

	if (line[0] == '\n' || !is_map_charset(line))
	{
		ft_printf_fd(2, "Error\nInvalid characters in the map !\n");
		return (false);
	}
	temp = parsing->map_in_line;
	parsing->map_in_line = handle_map(parsing->map_in_line, line);
	free(temp);
	return (true);
}

bool	parse_each_line(char *line, t_parsing *parsing)
{
	static bool in_map = false;

	if (is_path_charset(line))
	{
		if (in_map == true)
		{
			ft_printf_fd(2, "Error\nInvalid characters in the map !\n");
			return (false);
		}
		if (!get_path_by_id(get_path_id(line), parsing, line))
			return (false);
	}
	else if (is_map_charset(line) || in_map == true)
	{
		in_map = true;
		if (!get_map_line(line, parsing))
			return (false);
	}
	return (true);
}

bool	get_map_data(char *filename, t_parsing *parsing)
{
	int		fd;
	char	*line;

	fd = handle_open(filename);
	if (fd == -1)
		return (false);
	line = get_next_line(fd);
	parsing->map_in_line = ft_strdup("");
	while (line)
	{
		if (!parse_each_line(line, parsing))
			return (free(line), false);
		free(line);
		line = get_next_line(fd);
	}
	parsing->map = ft_split(parsing->map_in_line, '\n');
	free(parsing->map_in_line);
	return (true);
}

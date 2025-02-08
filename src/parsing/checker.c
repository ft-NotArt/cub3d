/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:25:18 by kaveo             #+#    #+#             */
/*   Updated: 2025/02/08 06:01:24 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

bool	get_map_line(char *line, t_parsing *parsing)
{
	char	*temp;

	if (line[0] == '\n' || !is_map_charset(line))
	{
		ft_printf_fd(2, "Error\nInvalid characters in the map !\n");
		return (false);
	}
	temp = parsing->map_in_line;
	parsing->map_in_line = ft_strjoin(parsing->map_in_line, line);
	free(temp);
	return (true);
}

// TODO handle when only having a single letter in paths
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
	if (!line)
		return (ft_printf_fd(2, "Error\nMap is empty !\n"), false);
	parsing->map_in_line = ft_strdup("");
	while (line)
	{
		if (!parse_each_line(line, parsing))
			return (free(line), false);
		free(line);
		line = get_next_line(fd);
	}
	parsing->map = ft_split(parsing->map_in_line, '\n');
	if (!parsing->map[0])
		return (ft_printf_fd(2, "Error\nMap is empty !\n"), false);
	return (true);
}

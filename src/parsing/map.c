/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:19:30 by albillie          #+#    #+#             */
/*   Updated: 2025/02/08 21:44:16 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	get_map_height(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		y++;
	}
	return (y);
}

size_t	get_higher_len(char **map)
{
	size_t	len;
	int		y;

	len = 0;
	y = 0;
	while (map[y])
	{
		if (ft_strlen(map[y]) > len)
		{
			len = ft_strlen(map[y]);
		}
		y++;
	}
	return (len);
}

static bool	get_map_line(char *line, t_parsing *parsing)
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

static bool	parse_each_line(char *line, t_parsing *parsing)
{
	static bool	in_map = false;

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
	else if (!is_path_charset(line) && !is_space_line(line))
	{
		ft_printf_fd(2, "Error\nInvalid character(s) in file\n");
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
		return (ft_printf_fd(2, "Error\nFile is empty !\n"), close(fd), false);
	parsing->map_in_line = ft_strdup("");
	while (line)
	{
		if (!parse_each_line(line, parsing))
			return (free(line), close(fd), false);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	parsing->map = ft_split(parsing->map_in_line, '\n');
	if (!parsing->map[0])
		return (ft_printf_fd(2, "Error\nMap is empty !\n"), false);
	return (true);
}

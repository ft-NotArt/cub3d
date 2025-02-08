/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:45:18 by kaveo             #+#    #+#             */
/*   Updated: 2025/02/08 20:08:25 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_map_charset(char *line)
{
	if (ft_strchr(line, '0') || ft_strchr(line, '1'))
	{
		return (true);
	}
	return (false);
}

bool	is_path_charset(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (ft_strnstr(line, "NO", len) || ft_strnstr(line, "SO", len)
		|| ft_strnstr(line, "WE", len) || ft_strnstr(line, "EA", len)
		|| ft_strnstr(line, "F", len) || ft_strnstr(line, "C", len)
		|| ft_strnstr(line, "DO", len))
	{
		return (true);
	}
	return (false);
}

static bool	is_playable_map(t_parsing *parsing)
{
	char	**flood_map;

	parsing->map_height = get_map_height(parsing->map);
	parsing->map_width = get_higher_len(parsing->map);
	parsing->player_dir = get_player_direction(parsing->map);
	parsing->player_x = get_player_x_pos(parsing->map);
	parsing->player_y = get_player_y_pos(parsing->map);
	flood_map = create_floodfill_map(parsing);
	free_str_array(parsing->map);
	flood_map[parsing->player_y][parsing->player_x] = '0';
	parsing->map = flood_map;
	flood_map = create_floodfill_map(parsing);
	flood_fill(flood_map, parsing->player_y, parsing->player_x, parsing);
	free_str_array(flood_map);
	return (true);
}

bool	is_valid_map(char *filename, t_parsing *parsing)
{
	if (!get_map_data(filename, parsing))
		return (false);
	else if (!check_paths_count(parsing))
		return (false);
	else if (!check_map_spawn(parsing->map))
		return (false);
	else if (!is_playable_map(parsing))
		return (false);
	return (true);
}

bool	is_space_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
		{
			return (false);
		}
		i++;
	}
	return (true);
}

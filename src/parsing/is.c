/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:45:18 by kaveo             #+#    #+#             */
/*   Updated: 2025/02/09 02:20:21 by anoteris         ###   ########.fr       */
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
	int		player_x ;
	int		player_y ;

	parsing->map_height = get_map_height(parsing->map);
	parsing->map_width = get_higher_len(parsing->map);
	parsing->player_dir = get_player_direction(parsing->map);
	player_x = get_player_x_pos(parsing->map);
	player_y = get_player_y_pos(parsing->map);
	parsing->pos->x = player_x + 0.5 ;
	parsing->pos->y = player_y + 0.5 ;
	flood_map = create_floodfill_map(parsing);
	free_str_array(parsing->map);
	flood_map[player_y][player_x] = '0';
	parsing->map = flood_map;
	flood_map = create_floodfill_map(parsing);
	flood_fill(flood_map, player_y, player_x, parsing);
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

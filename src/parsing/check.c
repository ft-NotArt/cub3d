/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 19:50:24 by albillie          #+#    #+#             */
/*   Updated: 2025/02/09 02:22:02 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_map_spawn(char **map)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E'
				|| map[y][x] == 'W')
			{
				count++;
			}
			x++;
		}
		y++;
	}
	if (count != 1)
		return (ft_printf_fd(2, "Error\nInvalid spawn(s) count !\n"), false);
	return (true);
}

bool	check_path_order(char *line, t_txtr_id id)
{
	char	*tmp;

	tmp = ft_strtrim(line, SPACES_SET);
	if ((id == NO && (tmp[0] != 'N' || tmp[1] != 'O' || !ft_isspace(tmp[2])))
		|| (id == SO && (tmp[0] != 'S' || tmp[1] != 'O' || !ft_isspace(tmp[2])))
		|| (id == WE && (tmp[0] != 'W' || tmp[1] != 'E' || !ft_isspace(tmp[2])))
		|| (id == EA && (tmp[0] != 'E' || tmp[1] != 'A' || !ft_isspace(tmp[2])))
		|| (id == DO && (tmp[0] != 'D' || tmp[1] != 'O' || !ft_isspace(tmp[2])))
		|| (id == FL && (tmp[0] != 'F' || !ft_isspace(tmp[1])))
		|| (id == CE && (tmp[0] != 'C' || !ft_isspace(tmp[1]))))
	{
		return (free(tmp), false);
	}
	return (free(tmp), true);
}

bool	check_paths_count(t_parsing *parsing)
{
	int	i;

	i = 0;
	while (i < NB_TXTRS)
	{
		if (!parsing->paths[i])
		{
			ft_printf_fd(2, "Error\nPath(s) are missing !\n");
			return (false);
		}
		i++;
	}
	return (true);
}

bool	check_map_chars(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != 'N'
				&& map[y][x] != 'S' && map[y][x] != 'W' && map[y][x] != 'E'
				&& map[y][x] != 'D' && map[y][x] != ' ' && map[y][x] != '\n')
			{
				return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}

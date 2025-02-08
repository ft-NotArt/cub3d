/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:07:16 by albillie          #+#    #+#             */
/*   Updated: 2025/02/08 23:12:12 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	get_player_x_pos(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if ((map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'W' || map[y][x] == 'E'))
			{
				return (x);
			}
			x++;
		}
		y++;
	}
	return (0);
}

size_t	get_player_y_pos(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if ((map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'W' || map[y][x] == 'E'))
			{
				return (y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

static t_txtr_id	convert_player_dir(char dir)
{
	if (dir == 'N')
	{
		return (NO);
	}
	else if (dir == 'S')
	{
		return (SO);
	}
	else if (dir == 'W')
	{
		return (WE);
	}
	else if (dir == 'E')
	{
		return (EA);
	}
	return (0);
}

t_txtr_id	get_player_direction(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if ((map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'W' || map[y][x] == 'E'))
			{
				return (convert_player_dir(map[y][x]));
			}
			x++;
		}
		y++;
	}
	return (0);
}

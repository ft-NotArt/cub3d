/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:19:30 by albillie          #+#    #+#             */
/*   Updated: 2025/02/07 20:10:04 by albillie         ###   ########.fr       */
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

size_t	get_higher_line_len(char **map)
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

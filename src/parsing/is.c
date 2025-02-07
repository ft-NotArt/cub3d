/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:45:18 by kaveo             #+#    #+#             */
/*   Updated: 2025/02/07 01:30:40 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_map_charset(char *line)
{
	if (ft_strchr(line, '0') || ft_strchr(line, '1') || ft_strchr(line, 'N')
		|| ft_strchr(line, 'S') || ft_strchr(line, 'E') || ft_strchr(line, 'W'))
	{
		return (true);
	}
	return (false);
}

bool	is_map_identifier(char *line)
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

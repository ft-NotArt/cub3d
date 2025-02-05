/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:45:18 by kaveo             #+#    #+#             */
/*   Updated: 2025/02/05 16:52:47 by albillie         ###   ########.fr       */
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
	if (ft_strnstr(line, "NO", ft_strlen(line)) || ft_strnstr(line, "SO", ft_strlen(line))
		|| ft_strnstr(line, "WE", ft_strlen(line)) || ft_strnstr(line, "EA", ft_strlen(line))
		|| ft_strnstr(line, "F", ft_strlen(line)) || ft_strnstr(line, "C", ft_strlen(line))
		|| ft_strnstr(line, "DO", ft_strlen(line)))
	{
		return (true);
	}
	return (false);
}

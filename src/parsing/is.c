/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:45:18 by kaveo             #+#    #+#             */
/*   Updated: 2025/02/04 20:43:19 by kaveo            ###   ########.fr       */
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
	if (ft_strnstr(line, "NO", ft_strlen(line)) || ft_strnstr(line, "SO", 2)
		|| ft_strnstr(line, "WE", 2) || ft_strnstr(line, "EA", 2)
		|| ft_strnstr(line, "F", 1) || ft_strnstr(line, "C", 1))
	{
		return (true);
	}
	return (false);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:57:03 by albillie          #+#    #+#             */
/*   Updated: 2025/02/08 20:12:43 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	get_path_len(char *temp)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (!ft_isspace(temp[i]))
	{
		i++;
	}
	while (ft_isspace(temp[i]))
	{
		i++;
	}
	while (!ft_isspace(temp[i]))
	{
		i++;
		len++;
	}
	return (len);
}

static bool	count_path_words(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		while (ft_isspace(line[i]))
		{
			i++;
		}
		if (line[i])
		{
			count++;
		}
		while (line[i] && !ft_isspace(line[i]))
		{
			i++;
		}
	}
	if (count != 2)
	{
		return (false);
	}
	return (true);
}

static char	*get_texture_path(char *line)
{
	char	*path;
	char	*temp;
	int		i;
	int		j;

	i = 2;
	temp = ft_strtrim(line, SPACES_SET);
	path = malloc(sizeof(char *) + (get_path_len(temp)));
	while (temp[i] && ft_isspace(temp[i]))
		i++;
	j = 0;
	while (temp[i] && !ft_isspace(temp[i]))
	{
		path[j++] = temp[i++];
	}
	path[j] = '\0';
	free(temp);
	return (path);
}

bool	get_path_by_id(t_txtr_id id, t_parsing *parsing, char *line)
{
	if (!check_path_order(line, id))
		return (ft_printf_fd(2, "Error\nInvalid path(s) id(s) !\n"), false);
	if (!count_path_words(line))
	{
		ft_printf_fd(2, "Error\nInvalid word(s) count on path line !\n");
		return (false);
	}
	else if (id == NO && !parsing->paths[NO])
		parsing->paths[NO] = get_texture_path(line);
	else if (id == SO && !parsing->paths[SO])
		parsing->paths[SO] = get_texture_path(line);
	else if (id == WE && !parsing->paths[WE])
		parsing->paths[WE] = get_texture_path(line);
	else if (id == EA && !parsing->paths[EA])
		parsing->paths[EA] = get_texture_path(line);
	else if (id == DO && !parsing->paths[DO])
		parsing->paths[DO] = get_texture_path(line);
	else if (id == FL && !parsing->paths[FL])
		parsing->paths[FL] = get_texture_path(line);
	else if (id == CE && !parsing->paths[CE])
		parsing->paths[CE] = get_texture_path(line);
	else
		return (ft_printf_fd(2, "Error\nPath duplication in map !\n"), false);
	return (true);
}

int	get_path_id(char *line)
{
	if (ft_strnstr(line, "NO", ft_strlen(line)))
		return (NO);
	else if (ft_strnstr(line, "SO", ft_strlen(line)))
		return (SO);
	else if (ft_strnstr(line, "WE", ft_strlen(line)))
		return (WE);
	else if (ft_strnstr(line, "EA", ft_strlen(line)))
		return (EA);
	else if (ft_strnstr(line, "DO", ft_strlen(line)))
		return (DO);
	else if (ft_strnstr(line, "F", ft_strlen(line)))
		return (FL);
	else if (ft_strnstr(line, "C", ft_strlen(line)))
		return (CE);
	return (-1);
}


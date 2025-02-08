/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:45:48 by kaveo             #+#    #+#             */
/*   Updated: 2025/02/08 23:14:25 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_parsing	*init_parsing(void)
{
	t_parsing	*parsing;

	parsing = malloc(sizeof(t_parsing));
	parsing->paths = malloc(sizeof(char *) * (NB_TXTRS + 1));
	ft_bzero(parsing->paths, (NB_TXTRS + 1) * sizeof(char *));
	parsing->map = NULL;
	parsing->map_in_line = NULL;
	parsing->map_height = 0;
	parsing->map_width = 0;
	parsing->pos = vector_init(0, 0);
	parsing->player_dir = 0;
	return (parsing);
}

int	handle_open(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror(filename);
		return (-1);
	}
	return (fd);
}

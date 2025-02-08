/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:16:13 by albillie          #+#    #+#             */
/*   Updated: 2025/02/08 02:04:38 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_parsing	*init_parsing()
{
	t_parsing	*parsing;

	parsing = malloc(sizeof(t_parsing));
	parsing->paths = malloc(sizeof(char *) * (PATHS_COUNT + 1));
	ft_bzero(parsing->paths, (PATHS_COUNT + 1) * sizeof(char *));
	parsing->map = NULL;
	parsing->map_in_line = NULL;
	parsing->map_height = 0;
	parsing->player_x = 0;
	parsing->player_y = 0;
	parsing->player_dir = 0;
	return (parsing);
}

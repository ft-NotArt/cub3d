/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:16:13 by albillie          #+#    #+#             */
/*   Updated: 2025/02/07 18:26:22 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_parsing	*init_parsing(char *filename)
{
	t_parsing	*parsing;

	parsing = malloc(sizeof(t_parsing));
	parsing->map = get_map_data(filename);
	parsing->paths = malloc(sizeof(char *) * 8);
	ft_bzero(parsing->paths, 8 * sizeof(char *));
	parsing->map_height = get_map_height(parsing->map);
	parsing->player_x = get_player_x_pos(parsing->map);
	parsing->player_y = get_player_y_pos(parsing->map);
	parsing->player_dir = get_player_direction(parsing->map);
	return (parsing);
}

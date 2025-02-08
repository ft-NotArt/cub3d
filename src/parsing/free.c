/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:29:00 by albillie          #+#    #+#             */
/*   Updated: 2025/02/08 02:01:39 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_all_paths(char **paths)
{
	int	i;

	i = 0;
	while (i < PATHS_COUNT)
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

void	free_parsing(t_parsing *parsing)
{
	if (parsing->map)
		free_str_array(parsing->map);
	if (parsing->paths)
		free_all_paths(parsing->paths);
	if (parsing->map_in_line)
		free(parsing->map_in_line);
	free(parsing);
}

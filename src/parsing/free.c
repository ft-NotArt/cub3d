/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:29:00 by albillie          #+#    #+#             */
/*   Updated: 2025/02/06 00:38:59 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_parsing(t_parsing *parsing)
{
	if (parsing->map)
		free_str_array(parsing->map);
	if (parsing->paths)
		free_str_array(parsing->paths);
	free(parsing);
}

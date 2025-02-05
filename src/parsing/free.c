/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:29:00 by albillie          #+#    #+#             */
/*   Updated: 2025/02/05 20:38:17 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_parsing(t_parsing *parsing)
{
	if (parsing->map)
		free_str_array(parsing->map);
	if (parsing->paths[NO])
		free(parsing->paths[NO]);
	if (parsing->paths[SO])
		free(parsing->paths[SO]);
	if (parsing->paths[WE])
		free(parsing->paths[WE]);
	if (parsing->paths[EA])
		free(parsing->paths[EA]);
	if (parsing->paths[DO])
		free(parsing->paths[DO]);
	if (parsing->paths[FL])
		free(parsing->paths[FL]);
	if (parsing->paths[CE])
		free(parsing->paths[CE]);
	free(parsing);
}

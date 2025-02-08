/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:46:42 by kaveo             #+#    #+#             */
/*   Updated: 2025/02/03 18:19:18 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	extension_checker(char *filename)
{
	if (!check_extension(filename, "cub"))
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Invalid map file extension, please use .cub !\n", 2);
		return (false);
	}
	return (true);
}

static bool	check_args_count(int ac)
{
	if (ac != 2)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Format -> ./cub3d <path_to_map>\n", 2);
		return (false);
	}
	return (true);
}

bool	args_checker(int ac, char **av)
{
	if (!check_args_count(ac))
		return (false);
	else if (!extension_checker(av[1]))
		return (false);
	return (true);
}

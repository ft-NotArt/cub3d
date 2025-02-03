/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:10:38 by albillie          #+#    #+#             */
/*   Updated: 2025/02/03 15:16:58 by kaveo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	check_extension(char *filename, char *extension)
{
	const char	*dot;

	if (!filename || !extension)
		return (false);
	dot = ft_strrchr(filename, '.');
	if (!dot)
		return (false);
	return ((ft_strcmp(dot + 1, extension)) == 0);
}

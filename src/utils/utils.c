/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 03:36:53 by anoteris          #+#    #+#             */
/*   Updated: 2025/02/09 04:08:08 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_mlx(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd((char *) mlx_strerror(mlx_errno), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

/**
 * @note The alpha is always at maximum,
 * as in the context of cub3d we don't have to deal w/ transparency
 * @param shadow wether or not to apply a darker tone on the color
 */
uint32_t	get_rgba(uint8_t r, uint8_t g, uint8_t b, bool shadow)
{
	if (shadow == 1)
	{
		r = (r >> 1) & 0b01111111 ;
		g = (g >> 1) & 0b01111111 ;
		b = (b >> 1) & 0b01111111 ;
	}
	return (r << 24 | g << 16 | b << 8 | 0xFF);
}

void	delete_textures_array(mlx_texture_t **to_delete)
{
	int	i ;

	i = -1 ;
	while (to_delete[++i])
		mlx_delete_texture(to_delete[i]);
	free(to_delete);
}

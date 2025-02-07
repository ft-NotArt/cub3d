/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:25:53 by anoteris          #+#    #+#             */
/*   Updated: 2025/02/07 21:08:18 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	cub3d_init_img(t_cub3d *cub3d, t_parsing *pars)
{
	int		i ;
	char	file[100];
	char	*itoa_res ;

	i = -1 ;
	while (++i < NB_TXTRS)
		cub3d->txtrs[i] = get_mlx_img(cub3d, pars, pars->txtr_paths[i]);
	cub3d->txtrs[i] = NULL ;
	mlx_resize_image(cub3d->txtrs[FL], 256, 256);
	mlx_resize_image(cub3d->txtrs[CE], 256, 256);
	i = -1 ;
	while (++i < NB_FRAMES)
	{
		ft_bzero(file, 100 * sizeof(char)) ;
		ft_strlcpy(file, "textures/AWP_anim/AWP_",
			ft_strlen("textures/AWP_anim/AWP_") + 1);
		itoa_res = ft_itoa(i) ;
		ft_strlcat(file, itoa_res, ft_strlen(file) + ft_strlen(itoa_res) + 1);
		free(itoa_res);
		ft_strlcat(file, ".png", ft_strlen(file) + ft_strlen(".png") + 1);
		cub3d->frames[i] = get_mlx_img(cub3d, pars, file);
		mlx_resize_image(cub3d->frames[i], SCREENWIDTH * (3.0 / 4.0), SCREENHEIGHT * (2.0 / 3.0));
	}
	cub3d->frames[i] = NULL ;
}

t_cub3d	*cub3d_init(t_parsing *pars)
{
	t_cub3d	*cub3d ;

	cub3d = malloc(sizeof(t_cub3d));
	cub3d->txtrs = malloc(sizeof(mlx_image_t *) * (NB_TXTRS + 1));
	ft_bzero(cub3d->txtrs, sizeof(mlx_image_t *) * (NB_TXTRS + 1));
	cub3d->frames = malloc(sizeof(mlx_image_t *) * (NB_FRAMES + 1));
	ft_bzero(cub3d->frames, sizeof(mlx_image_t *) * (NB_FRAMES + 1));
	cub3d->map = pars->map ;
	pars->map = NULL ;
	cub3d->raycast = raycast_init(pars);
	cub3d->mlx = mlx_init(SCREENWIDTH, SCREENHEIGHT, "CUB3D", false);
	if (!cub3d->mlx)
		(error_mlx(), free_parsing(pars), close_failure(cub3d));
	cub3d->screen = mlx_new_image(cub3d->mlx, SCREENWIDTH, SCREENHEIGHT);
	cub3d_init_img(cub3d, pars);
	cub3d->frame = -1 ;
	return (cub3d);
}

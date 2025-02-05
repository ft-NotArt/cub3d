/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:40:26 by anoteris          #+#    #+#             */
/*   Updated: 2025/02/05 14:57:51 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*** INCLUDE ***/

# include "libft.h"
# include "get_next_line.h"
# include "MLX42/MLX42.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include <stdbool.h>

/*** DEFINE ***/

# ifndef SCREENWIDTH
#  define SCREENWIDTH 800
# endif

# ifndef SCREENHEIGHT
#  define SCREENHEIGHT 600
# endif

# define MOVE_SPEED 0.15
# define ROT_SPEED 0.05

/*** TYPEDEF ***/

typedef enum s_txtr_id
{
	NO,
	SO,
	WE,
	EA,
	DO,
	FL,
	CE
}	t_txtr_id ;

typedef struct s_point
{
	int	x ;
	int	y ;
}	t_point ;

typedef struct s_vector
{
	double	x ;
	double	y ;
}	t_vector ;

//TODO: Could modify paths to an array (then use txtr_id enum as index)
typedef	struct	s_parsing
{
	char		**map;
	char		**txtr_paths;
	struct s_vector	*pos ;
	t_txtr_id		dir ;
}				t_parsing;

typedef struct s_raycasting
{
	struct s_vector	*pos ;
	struct s_vector	*dir ;
	struct s_vector	*plane ;
	struct s_vector	*rayDir ;
	struct s_vector	*deltaDist ;
	struct s_vector	*sideDist ;
	struct s_vector	*tex ;
	struct s_vector	*floor ;
	struct s_point	*map ;
	struct s_point	*step ;
	int				lineHeight ;
	int				drawStart ;
	int				drawEnd ;
	double			perpWallDist;
	double			rowDist ;
	t_txtr_id		side ;
}	t_raycast;


typedef struct s_cub3d
{
	char				**map ;
	mlx_t				*mlx ;
	mlx_image_t			*screen ;
	mlx_image_t			**images ;
	struct s_raycasting	*raycast ;
}	t_cub3d ;

/*** FUNCTIONS ***/

// Game
void		frame_loop(void *param);
void		keyboard_hook(mlx_key_data_t keydata, void *param);
void		move(t_cub3d *cub3d, double dir1, double dir2, double move_speed);
void		rotate(t_cub3d *cub3d, double rot_speed);

// Raycasting
void		raycasting(t_cub3d *cub3d);
void		draw_background(t_cub3d *cub3d, t_raycast *raycast,
	mlx_image_t *floor, mlx_image_t *ceilling);
void		calc_deltaDist(t_raycast *raycast);
void		calc_step_and_sideDist(t_raycast *raycast);
void		calc_line(t_raycast *raycast);
int			calc_texX(t_raycast *raycast, mlx_image_t *img);

// Init
t_cub3d		*cub3d_init(t_parsing *pars);
t_vector	*vector_init(double x, double y);

// Utils
void		error_mlx(void);
mlx_image_t	*get_mlx_img(t_cub3d *cub3d, t_parsing *pars, char *file_path);
uint32_t	get_rgba(uint8_t r, uint8_t g, uint8_t b, bool shadow);

// Free
void		free_parsing(t_parsing *parsing);
void		free_raycast(t_raycast *raycast);
void		free_cub3d(t_cub3d *cub3d);

// Close
void		close_success(void *param);
void		close_failure(void *param);

#endif
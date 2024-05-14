/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:25:26 by jmertane          #+#    #+#             */
/*   Updated: 2024/05/13 09:18:52 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H

# include <libft.h>
# include <error.h>

# include <stdbool.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <math.h>
# include <stdio.h>
# include "../mlx/include/MLX42/MLX42.h" 

# define CELLSIZE 64
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

# define PI 3.1415926535898
# define DEGREE PI / 360

# define EAST 0
# define NORTH PI / 2
# define WEST PI
# define SOUTH 3 * PI / 2

# define STEP_ANGLE 0.1
# define STEP_MOVE 8
# define BPP sizeof(int)

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;
	float	fov;
	int		dof;
}	t_player;

typedef struct s_vector
{
	float	x;
	float	y;
	float	angle;
}	t_vector;

typedef struct s_mapinfo
{
	char	**matrix;
	int		width;
	int		height;
}	t_mapinfo;

typedef struct s_texture
{
	t_vector			vec;
	float				scale;
	void				*tex;
	void				*img;
	int					fd;
	struct s_texture	*next;
}	t_texture;

typedef struct s_cubed
{
	t_player	player;
	t_mapinfo	map;
	t_texture	*texture;
	void		*mlx;
}	t_cubed;

#endif
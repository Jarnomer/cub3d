/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_calc_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:52:01 by jmertane          #+#    #+#             */
/*   Updated: 2024/06/27 17:52:04 by jmertane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cubed_bonus.h>

static t_image	assign_texture(char c)
{
	if (c == MAP_AMMO)
		return (IMG_AM);
	else
		return (IMG_HL);
}

void	calc_spr_tex(int map[2], t_camera *spr, t_camera *tex, t_cubed *game)
{
	static int	scale_factor = 2000;
	static int	sprite_limit = 5000;
	int			size;

	spr->a = assign_texture(get_map_element(map[X], map[Y], game));
	size = game->asset[(int)spr->a]->height;
	spr->dx = size / spr->dy * scale_factor;
	if (spr->dx < 0)
		spr->dx = 0;
	if (spr->dx > sprite_limit)
		spr->dx = sprite_limit;
	spr->dy = spr->dx;
	tex->dx = size / spr->dx;
	tex->dy = size / spr->dy;
	tex->y = size;
	tex->x = 0;
}

void	calc_spr_scr(int map[2], t_camera *spr, t_camera *cam)
{
	static float	x_scale = -2000.0f;
	static float	y_scale = 400.0f;
	int				x;
	int				y;

	x = map[X] * CELLSIZE + CELLSIZE / 2;
	y = map[Y] * CELLSIZE + CELLSIZE / 2;
	spr->x = x - cam->x;
	spr->y = y - cam->y;
	spr->z = (float)SCREEN_HEIGHT / 2;
	spr->dx = spr->y * -cos(cam->a) + spr->x * sin(cam->a);
	spr->dy = spr->x * cos(cam->a) + spr->y * sin(cam->a);
	spr->x = spr->dx;
	spr->y = spr->dy;
	spr->x = spr->x * x_scale / spr->y + SCREEN_WIDTH / 2;
	spr->y = spr->z * y_scale / spr->y + SCREEN_HEIGHT / 2;
}
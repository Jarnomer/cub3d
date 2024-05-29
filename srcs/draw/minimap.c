/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:12:26 by jmertane          #+#    #+#             */
/*   Updated: 2024/05/29 16:09:35 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cubed.h>

/*mlx_image_t	*mplayer;
mlx_image_t	*mwall;
mlx_image_t	*mfloor;
mlx_image_t	*msfloor;*/

/*void	check_pixel_limits(float *pixelX, float *pixelY)
{
	if (*pixelY >= 255)
			*pixelY = 255;
		if (*pixelY < 0)
			*pixelY = 0;
		if (*pixelX >= 255)
			*pixelX = 255;
		if (*pixelX < 0)
			*pixelX = 0;
}

static	void	draw_rays(t_vector	*ray)
{
	float	deltaX;
	float	deltaY;
	int		pixels;
	float	pixelX;
	float	pixelY;

	deltaX = ray->x / 2 - mplayer->instances[0].x;
	deltaY = ray->y / 2 - mplayer->instances[0].y;
	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	pixelX = mplayer->instances[0].x;
	pixelY = mplayer->instances[0].y;
	while(pixels)
	{
		check_pixel_limits(&pixelX, &pixelY);
		if (msfloor == NULL)
			mlx_put_pixel(mfloor, (int)pixelX, (int)pixelY, 160);
		else
			mlx_put_pixel(msfloor, (int)pixelX, (int)pixelY, 160);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
}

void	calculate_rays(t_cubed *game)
{
	t_vector	*ray;
	float		angle;
	int			i;

	change_mini_foor(game);
	draw_minimap(game, 1);
	angle = game->cam->a;
	ft_rotate(&angle, FOV / 2, ROTATE_LEFT);
	ray = safe_calloc(sizeof(t_vector), game);
	i = 0;
	while (i < 66)
	{
		ray->a = angle;
		calculate_ray(ray, game);
		ft_rotate(&angle, DEGREE, ROTATE_RIGHT);
		draw_rays(ray);
		i++;
	}
	free(ray);
}

void	change_mini_foor(t_cubed *game)
{
	mlx_image_t		*floor;

	if (msfloor == NULL)
	{
		mlx_delete_image(game->mlx, mfloor);
		mfloor = NULL;
		floor = mlx_new_image(game->mlx, CELLSIZE * 4, CELLSIZE * 4);
		ft_memset(floor->pixels, 220, floor->width * floor->height * BPP);
		msfloor = floor;
	}
	else
	{
		mlx_delete_image(game->mlx, msfloor);
		msfloor = NULL;
		floor = mlx_new_image(game->mlx, CELLSIZE * 4, CELLSIZE * 4);
		ft_memset(floor->pixels, 220, floor->width * floor->height * BPP);
		mfloor = floor;
	}
}

void	move_minimap(t_cubed *game, t_action action)
{
	calculate_rays(game);

	if (action == MOVE_UP)
		mplayer->instances[0].y -= STEP_MOVEMENT / 2;
	else if (action == MOVE_DOWN)
		mplayer->instances[0].y += STEP_MOVEMENT / 2;
	else if (action == MOVE_LEFT)
		mplayer->instances[0].x -= STEP_MOVEMENT / 2;
	else if (action == MOVE_RIGHT)
		mplayer->instances[0].x += STEP_MOVEMENT / 2;
}
*/
/*
void	check_pixel(t_cubed *game, int x, int y)
{
	int	color;

	color = get_color(game->map->minimap, x, y);
	if (game->map->matrix[y][x] == '0' && color != )
	{
		ft_putpixel(x, y, , game);
	}
	else if (game->map->matrix[y][x] == '1' && color != )
	{
		float i = 0;
		while (++i < 64)
			mlx_put_pixel(game->map->minimap, x + i, y, );
		
	}
	else if (game->map->matrix[y][x] == '2' && color != )
	{
		ft_putpixel(x, y, , game);
	}
}

void	draw_minimap(t_cubed *game)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x= game->cam->x / CELLSIZE;
	y= game->cam->y / CELLSIZE;
	i = 0;
	while (i < 5)
	{
		j = 0;
		while(j < 0)
		{

				check_pixel(game, x + j, y - i);
				check_pixel(game, x + j, y + i);
				check_pixel(game, x - j, y - i);
				check_pixel(game, x - j, y + i);
				j++;
		}
		i++;
	}

} */

static int32_t	get_map(int px, int py, t_cubed *game)
{
	int	x;
	int	y;

	x = px / CELLSIZE;
	y = py / CELLSIZE;
	if (x < 0 || x >= game->map->width
		|| y < 0 || y >= game->map->height)
		return (game->col[COL_MF]);
	return (game->col[COL_MW]);
}

static void	draw_blah(int x, t_cubed *game)
{
	int32_t	color;
	int	px;
	int	py;
	int y;

	y = 0;
	px = game->cam->x - (MAPGRID / 2) * CELLSIZE;
	py = game->cam->y + (MAPGRID / 2) * CELLSIZE;
	while (y < MAPCELL * MAPGRID)
	{
		color = get_map(px, py, game);
		ft_putpixel(x, y, color, game);
		py++;
		y++;
	}
}

void	draw_minimap(t_cubed *game)
{
	int			column;

	column = 0;
	game->col[COL_MF] = get_rgba(50, 200, 50, 255);
	game->col[COL_MW] = get_rgba(50, 50, 200, 255);
	while (column < MAPCELL * MAPGRID)
	{
		draw_blah(column++, game);
	}
}
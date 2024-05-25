/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 21:01:01 by jmertane          #+#    #+#             */
/*   Updated: 2024/05/23 13:25:26 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cubed.h>

char *test_map[] = { "11111111\n",
					"10100001\n",
					"10100001\n",
					"10100001\n",
					"10000001\n",
					"10000101\n",
					"10000001\n",
					"11111111" };

static void	init_map(t_mapinfo *map, t_vector *cam, char *file)
{
	map->filename = file;
	map->filefd = -1;
	map->matrix = test_map;
	map->width = 8;
	map->height = 8;
	cam->x = 4 * CELLSIZE;
	cam->y = 4 * CELLSIZE;
	cam->a = NORTH - 0.1;
}

void	init_game(t_cubed *game, char *file)
{
	ft_bzero(game, sizeof(t_cubed));
	game->map = safe_calloc(sizeof(t_mapinfo), game);
	game->cam = safe_calloc(sizeof(t_vector), game);
	game->imgs = safe_calloc(sizeof(mlx_image_t) * (GAME_ASSETS + 1), game);
	init_map(game->map, game->cam, file);
	game->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE, false);
	if (!game->mlx)
		error_exit(ERR_MLX, MSG_MLX, game);
	init_minimap(game);
}

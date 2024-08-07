/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+        */
/*                                               +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:32:06 by jmertane          #+#    #+#             */
/*   Updated: 2024/05/14 09:18:53 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cubed.h>

static void	run_game(t_cubed *game)
{
	mlx_close_hook(game->mlx, hook_close, game);
	mlx_key_hook(game->mlx, hook_action, game);
	mlx_loop_hook(game->mlx, hook_movement, game);
	mlx_loop_hook(game->mlx, render_scenario, game);
	mlx_loop(game->mlx);
}

static void	parse_file(t_cubed *game, char *file)
{
	parse_filename(game, file);
	parse_elements(game);
	parse_mapinfo(game);
}

static void	init_game(t_cubed *game, char *file)
{
	ft_bzero(game, sizeof(t_cubed));
	game->cam = safe_calloc(sizeof(t_camera), game);
	game->map = safe_calloc(sizeof(t_mapinfo), game);
	game->map->filename = file;
	game->map->filefd = FAILURE;
	game->mlx = mlx_init(SCREEN_WIDTH,
			SCREEN_HEIGHT, SCREEN_TITLE, false);
	if (!game->mlx)
		error_exit(ERR_MLX, MSG_MLX, game);
	game->canvas = safe_img(SCREEN_WIDTH, SCREEN_HEIGHT, NULL, game);
	safe_draw(game->canvas, 0, 0, game);
}

int	main(int argc, char **argv)
{
	t_cubed	game;

	if (argc != 2)
		error_exit(ERR_ARGC, MSG_ARGC, NULL);
	init_game(&game, argv[1]);
	parse_file(&game, argv[1]);
	run_game(&game);
	free_exit(&game, NOERROR);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 21:01:07 by jmertane          #+#    #+#             */
/*   Updated: 2024/05/18 21:57:52 by jmertane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cubed.h>

void	hook_close(void *param)
{
	t_cubed	*game;

	game = param;
	free_exit(game, NOERROR);
}

static void	clean_assets(t_texture **lst, t_cubed *game)
{
	t_texture	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		if ((*lst)->fd != -1)
			close((*lst)->fd);
		if ((*lst)->img != NULL)
			mlx_delete_image(game->mlx, (*lst)->img);
		if ((*lst)->tex != NULL)
			mlx_delete_texture((*lst)->tex);
		if ((*lst)->vec != NULL)
			free((*lst)->vec);
		free(*lst);
		*lst = temp;
	}
	free(*lst);
	*lst = NULL;
}

static void	destruct_map(t_mapinfo *map, t_cubed *game)
{
	if (map->fd != -1)
		close(map->fd);
	if (map->tex != NULL)
		clean_assets(&map->tex, game);
	free(map);
	map = NULL;
}

void	free_exit(t_cubed *game, int excode)
{
	if (!game)
		return ;
	if (game->mlx != NULL)
		mlx_close_window(game->mlx);
	if (game->map != NULL)
		destruct_map(game->map, game);
	if (game->tex != NULL)
		clean_assets(&game->tex, game);
	if (game->mlx != NULL)
		mlx_terminate(game->mlx);
	if (game->cam != NULL)
		free(game->cam);
	exit(excode);
}

/* int	i; */
/* if (map->matrix != NULL) */
/* { */
/* 	i = 0; */
/* 	while (*map->matrix[i]) */
/* 		free(map->matrix[i++]); */
/* 	free(map->matrix); */
/* 	map->matrix = NULL; */
/* } */

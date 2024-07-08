/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:48:31 by jmertane          #+#    #+#             */
/*   Updated: 2024/05/31 14:44:46 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cubed_bonus.h>

static int	load_element(bool *elements, char *id, t_cubed *game)
{
	if (!elements[0] && !ft_strncmp(id, "NO ", 3))
		load_texture(IMG_NO, id + 2, &elements[0], game);
	else if (!elements[1] && !ft_strncmp(id, "SO ", 3))
		load_texture(IMG_SO, id + 2, &elements[1], game);
	else if (!elements[2] && !ft_strncmp(id, "WE ", 3))
		load_texture(IMG_WE, id + 2, &elements[2], game);
	else if (!elements[3] && !ft_strncmp(id, "EA ", 3))
		load_texture(IMG_EA, id + 2, &elements[3], game);
	else if (!elements[4] && !ft_strncmp(id, "F ", 2))
		load_color(COL_FL, id + 1, &elements[4], game);
	else if (!elements[5] && !ft_strncmp(id, "C ", 2))
		load_color(COL_RF, id + 1, &elements[5], game);
	else if (*game->gnl == MAP_WALL || *game->gnl == ' ')
		error_exit(ERR_MAP, MSG_ASSET, game);
	else
		error_exit(ERR_ELEM, MSG_ELEM, game);
	return (1);
}

void	parse_elements(t_cubed *game)
{
	bool	elements[6];
	int		loaded;

	loaded = 0;
	ft_bzero(&elements, 6);
	while (true)
	{
		free_single(&game->gnl);
		if (loaded == 6)
			break ;
		game->gnl = get_next_line(game->map->filefd);
		if (!game->gnl)
			error_exit(ERR_MAP, MSG_NOMAP, game);
		if (ft_is_empty_line(game->gnl))
			continue ;
		loaded += load_element(elements, game->gnl, game);
	}
}

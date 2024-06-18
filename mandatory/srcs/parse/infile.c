/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infile.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 21:01:01 by jmertane          #+#    #+#             */
/*   Updated: 2024/05/27 19:15:02 by jmertane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cubed.h>

void	open_infile(t_cubed *game)
{
	t_mapinfo	*map;
	char		*file;
	char		buffer;

	map = game->map;
	file = map->filename;
	map->filefd = open(file, O_DIRECTORY);
	if (map->filefd != FAILURE)
		error_exit(ERR_MAP, MSG_FLDR, game);
	map->filefd = open(file, O_RDONLY);
	if (map->filefd == FAILURE)
		error_exit(ERR_MAP, strerror(errno), game);
	read(map->filefd, &buffer, sizeof(char));
	if (!buffer)
		error_exit(ERR_MAP, MSG_VOID, game);
	close(map->filefd);
	map->filefd = open(file, O_RDONLY);
}

void	parse_filename(t_cubed *game)
{
	char	*file;
	char	*extn;
	int		len;

	file = game->map->filename;
	extn = ft_strrchr(file, '.');
	len = ft_strlen(file) - 4;
	if (len <= 0 || !extn || ft_strncmp(extn, ".cub", 5))
		error_exit(ERR_MAP, MSG_EXTN, game);
	if (len > 0 && !ft_strncmp(extn - 1, "/.cub", 6))
		error_exit(ERR_MAP, MSG_NAME, game);
}

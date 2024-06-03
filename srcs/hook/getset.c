/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:21:50 by jmertane          #+#    #+#             */
/*   Updated: 2024/06/03 09:25:50 by jmertane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cubed.h>

void	get_buffer(int *buffer, t_cubed *game)
{
	buffer[X] = BUMP_BUFFER;
	buffer[Y] = BUMP_BUFFER;
	if (game->cam->dx < 0)
		buffer[X] = -buffer[X];
	if (game->cam->dy < 0)
		buffer[Y] = -buffer[Y];
}

void	get_position(int *player, t_cubed *game)
{
	player[X] = game->cam->x / CELLSIZE;
	player[Y] = game->cam->y / CELLSIZE;
}
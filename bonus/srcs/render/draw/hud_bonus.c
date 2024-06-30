/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:56:17 by vsavolai          #+#    #+#             */
/*   Updated: 2024/06/30 11:52:40 by jmertane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cubed_bonus.h>

void	draw_hud(t_cubed *game)
{
	int	height;
	int	width;

	height = SCREEN_HEIGHT - HUD_HEIGHT;
	while (height == SCREEN_HEIGHT)
	{
		width = 0;
		while (width < SCREEN_WIDTH)
		{
			ft_put_pixel(width, height, COLOR_HUD, game->asset[IMG_HD]);
			width++;
		}
		height++;
	}
}

/* char *s = get_player_value(game->plr->health, game); */
/* mlx_put_string(game->mlx, s, 300, SCREEN_HEIGHT - 300); */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 22:17:16 by jmertane          #+#    #+#             */
/*   Updated: 2024/05/26 22:17:19 by jmertane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cubed.h>

int32_t	ft_getrgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

static int	valid_pixel(mlx_image_t *img, uint32_t x, uint32_t y)
{
	return (x < img->width && y < img->height);
}

static int32_t	get_color(mlx_image_t *img, uint32_t x, uint32_t y)
{
	uint8_t	*start;

	if (!img || !valid_pixel(img, x, y))
		return (0xFF000000);
	start = img->pixels + (y * img->width + x) * BPP;
	return (ft_getrgba(*start, *(start + 1), *(start + 2), *(start + 3)));
}

void	ft_putpixel(int x, int y, int32_t color, t_cubed *game)
{
	if (!valid_pixel(game->img[ELEM_BG], x, y)
		|| get_color(game->img[ELEM_BG], x, y) == color)
		return ;
	mlx_put_pixel(game->img[ELEM_BG], x, y, color);
}
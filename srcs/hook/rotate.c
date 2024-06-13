/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 22:17:29 by jmertane          #+#    #+#             */
/*   Updated: 2024/06/11 15:43:09 by jmertane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cubed.h>

void	fix_fisheye(t_vector *ray, float angle)
{
	ft_rotate(&angle, ray->a, ROTATE_LEFT);
	ray->d *= cos(angle);
}

void	rotate_camera(t_cubed *game, t_action action)
{
	t_camera	cam;

	get_camera(&cam, game);
	if (action == ROTATE_LEFT)
		ft_rotate(&cam.a, STEP_ANGLE, ROTATE_LEFT);
	else
		ft_rotate(&cam.a, STEP_ANGLE, ROTATE_RIGHT);
	cam.dx = cos(cam.a) * STEP_MOVEMENT;
	cam.dy = sin(cam.a) * STEP_MOVEMENT;
	set_camera(&cam, game);
}

void	ft_rotate(float *target, float angle, t_action action)
{
	if (action == ROTATE_LEFT)
	{
		*target -= angle;
		if (*target < 0)
			*target += 2 * PI;
	}
	else if (action == ROTATE_RIGHT)
	{
		*target += angle;
		if (*target > 2 * PI)
			*target -= 2 * PI;
	}
}

float	ft_degtorad(float degree)
{
	return (degree * PI / 180);
}

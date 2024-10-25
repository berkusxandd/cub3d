/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince < bince@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:17:48 by bince             #+#    #+#             */
/*   Updated: 2024/10/25 14:19:04 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

float	angle_normalizer(float a)
{
	if (a < 0)
		a += 2 * M_PI;
	else if (a > 2 * M_PI)
		a -= 2 * M_PI;
	return (a);
}
float	get_perp_dist(t_data *g_data, t_ray ray)
{
	float	delta_angle;
	float	perp_dist;

	if (ray.side == 0 || ray.side == 1)
		perp_dist = (ray.side_dist_x - ray.delta_dist_x);
	else
	{
		perp_dist = (ray.side_dist_y - ray.delta_dist_y);
	}
	delta_angle = ray.ray_angle - g_data->p_a;
	if (delta_angle > M_PI)
		delta_angle -= 2 * M_PI;
	else if (delta_angle < -M_PI)
		delta_angle += 2 * M_PI;
	perp_dist = perp_dist * cos(delta_angle);
	return (perp_dist);
}

void	set_elapsed_time(t_data *g_data)
{
	struct timeval	tv;
	long			t2;
	long			t1;

	t2 = g_data->t1;
	gettimeofday(&tv, NULL);
	g_data->t1 = (tv.tv_sec * 1000 + tv.tv_usec / 1000);
	t1 = g_data->t1;
	g_data->delta_time = (t1 - t2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince < bince@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:16:15 by bince             #+#    #+#             */
/*   Updated: 2024/10/28 14:16:36 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	render_env(t_data *g_data, t_vector2 v2, t_walls walls)
{
	if (v2.y > 0 && v2.y < walls.draw_start)
		mlx_put_pixel(&g_data->img_data, v2.x, v2.y, g_data->texture[C].color);
	else
		mlx_put_pixel(&g_data->img_data, v2.x, v2.y, g_data->texture[F].color);
}

void	render_scene(t_data *g_data)
{
	t_vector2	v2;
	t_ray		ray;
	t_walls		walls;
	float		perp_dist;

	v2.x = 0;
	while (v2.x < WWIN)
	{
		ray = create_ray(g_data, v2.x);
		if (ray.hit == 1)
		{
			perp_dist = get_perp_dist(g_data, ray);
			walls = create_walls(perp_dist);
			v2.y = -1;
			while (++v2.y < HWIN)
			{
				if (v2.y > walls.draw_start && v2.y < walls.draw_end)
					render_wall_textures(g_data, v2, ray, walls);
				else
					render_env(g_data, v2, walls);
			}
		}
		v2.x++;
	}
}

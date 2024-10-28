/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince < bince@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:14:07 by bince             #+#    #+#             */
/*   Updated: 2024/10/28 14:16:46 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_tex_x(t_data *g_data, t_ray ray, float perp_dist)
{
	float	wall_x;
	int		tex_x;

	if (ray.side < 2)
		wall_x = ray.ray_y / TILE_SIZE + perp_dist * ray.ray_dir_y;
	else
		wall_x = ray.ray_x / TILE_SIZE + perp_dist * ray.ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (g_data->texture[ray.side].width));
	if (ray.side == 0 || ray.side == 2)
		tex_x = g_data->texture[ray.side].width - tex_x - 1;
	return (tex_x);
}

int	get_tex_y(t_data *g_data, t_walls walls, t_ray ray, int y)
{
	int	tex_y;

	tex_y = ((y - walls.tex_start) * g_data->texture[ray.side].height)
		/ walls.line_height;
	return (tex_y);
}

void	render_wall_textures(t_data *g_data, t_vector2 v2, t_ray ray,
		t_walls walls)
{
	int	tex_x;
	int	tex_y;
	int	color;

	tex_x = get_tex_x(g_data, ray, get_perp_dist(g_data, ray));
	tex_y = get_tex_y(g_data, walls, ray, v2.y);
	color = get_pixel_color(&g_data->texture[ray.side], tex_x, tex_y);
	mlx_put_pixel(&g_data->img_data, v2.x, v2.y, color);
}

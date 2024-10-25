/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince < bince@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:13:54 by bince             #+#    #+#             */
/*   Updated: 2024/10/25 14:26:19 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_walking_to_wall(t_data *g_data)
{
	float	new_x;
	float	new_y;
	int		new_x_map;
	int		new_y_map;

	new_x = g_data->p_x;
	new_y = g_data->p_y;
	new_x += g_data->walk * cos(g_data->p_a) * g_data->speed
		* g_data->delta_time;
	new_y += g_data->walk * sin(g_data->p_a) * g_data->speed
		* g_data->delta_time;
	new_x_map = (int)(new_x / TILE_SIZE);
	new_y_map = (int)(new_y / TILE_SIZE);
	if (new_y_map < 0 || new_y_map > g_data->m_len || new_x_map < 0
		|| new_x_map > g_data->m_width)
		return (1);
	return (g_data->map[new_y_map][new_x_map] == '1');
}

int	is_sidewalking_to_wall(t_data *g_data)
{
	float	new_x;
	float	new_y;
	int		new_x_map;
	int		new_y_map;

	new_x = g_data->p_x;
	new_y = g_data->p_y;
	new_x += g_data->side_walk * sin(g_data->p_a) * g_data->speed
		* g_data->delta_time;
	new_y -= g_data->side_walk * cos(g_data->p_a) * g_data->speed
		* g_data->delta_time;
	new_x_map = (int)(new_x / TILE_SIZE);
	new_y_map = (int)(new_y / TILE_SIZE);
	if (new_y_map < 0 || new_y_map > g_data->m_len || new_x_map < 0
		|| new_x_map > g_data->m_width)
		return (1);
	return (g_data->map[new_y_map][new_x_map] == '1');
}

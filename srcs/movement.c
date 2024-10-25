/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince < bince@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:31:06 by bince             #+#    #+#             */
/*   Updated: 2024/10/25 13:31:09 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

float	move_x(t_data *g_data)
{
	return (g_data->walk * cos(g_data->p_a) * g_data->speed
		* g_data->delta_time);
}

float	move_y(t_data *g_data)
{
	return (g_data->walk * sin(g_data->p_a) * g_data->speed
		* g_data->delta_time);
}

float	side_walk_x(t_data *g_data)
{
	return (g_data->side_walk * sin(g_data->p_a) * g_data->speed
		* g_data->delta_time);
}

float	side_walk_y(t_data *g_data)
{
	return (g_data->side_walk * cos(g_data->p_a) * g_data->speed
		* g_data->delta_time);
}

void	player_move(t_data *g_data)
{
	if (g_data->walk != 0)
	{
		if (is_walking_to_wall(g_data) == 0)
		{
			g_data->p_x += move_x(g_data);
			g_data->p_y += move_y(g_data);
		}
	}
	if (g_data->side_walk != 0)
	{
		if (is_sidewalking_to_wall(g_data) == 0)
		{
			g_data->p_x += side_walk_x(g_data);
			g_data->p_y -= side_walk_y(g_data);
		}
	}
}

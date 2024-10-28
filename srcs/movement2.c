/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince < bince@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:15:59 by bince             #+#    #+#             */
/*   Updated: 2024/10/28 14:16:01 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	player_rotate(t_data *g_data)
{
	if (g_data->rotate == -1)
		g_data->p_a -= 0.005 * g_data->delta_time;
	else if (g_data->rotate == 1)
		g_data->p_a += 0.005 * g_data->delta_time;
	g_data->p_a = angle_normalizer(g_data->p_a);
}

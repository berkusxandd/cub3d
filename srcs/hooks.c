/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince < bince@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:15:38 by bince             #+#    #+#             */
/*   Updated: 2024/10/25 14:30:29 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_press_hook(int keycode, t_data *game_data)
{
	if (keycode == KEY_W)
		game_data->walk = 1;
	if (keycode == KEY_A)
		game_data->side_walk = 1;
	if (keycode == KEY_D)
		game_data->side_walk = -1;
	if (keycode == LEFT_ARROW)
		game_data->rotate = -1;
	if (keycode == KEY_S)
		game_data->walk = -1;
	if (keycode == RIGHT_ARROW)
		game_data->rotate = 1;
	if (keycode == XK_Escape)
	 	f_exit(game_data);
	return (0);
}

int	key_release_hook(int keycode, t_data *g_data)
{
	if (keycode == KEY_W)
		g_data->walk = 0;
	if (keycode == LEFT_ARROW)
		g_data->rotate = 0;
	if (keycode == KEY_A)
		g_data->side_walk = 0;
	if (keycode == KEY_D)
		g_data->side_walk = 0;
	if (keycode == KEY_S)
		g_data->walk = 0;
	if (keycode == RIGHT_ARROW)
		g_data->rotate = 0;
	return (0);
}

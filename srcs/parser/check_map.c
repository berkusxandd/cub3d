/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince < bince@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:45:57 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/17 14:40:49 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_ok(char c, int y)
{
	if (y == 0 && c == '\n')
		return (1);
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == '0')
		return (0);
	if (c == '1' || c == '0' || c == ' ' || c == '\n')
		return (0);
	return (1);
}

static int	invalid_char(t_data *data, char **map)
{
	int		x;
	int		y;

	x = -1;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
		{
			if (is_ok(map[x][y], y))
				return (EXIT_FAILURE);
			if (map[x][y] == 'N' || map[x][y] == 'S' || map[x][y] == 'W' ||
				map[x][y] == 'E')
			{
				if (data->start_x)
					return (EXIT_FAILURE);
				data->start_x = x;
				data->start_y = y;
				data->p_dir = data->map[data->start_x][data->start_y];
				data->map[data->start_x][data->start_y] = '0';
			}
		}
	}
	return (EXIT_SUCCESS);
}

static int	check_walls(t_data *data, char **map, int x, int y)
{
	if (map[x][y] == '9')
		return (EXIT_SUCCESS);
	map[x][y] = '9';
	if (y == 0 || y == ft_strlen(map[x]) - 1 || x == 0 || x == data->m_len - 1)
		return (EXIT_FAILURE);
	if (map[x - 1][y] == ' ' || map[x + 1][y] == ' ' ||
		map[x][y - 1] == ' ' || map[x][y + 1] == ' ')
		return (EXIT_FAILURE);
	if (map[x - 1][y] == '\0' || map[x + 1][y] == '\0' ||
		map[x][y - 1] == '\0' || map[x][y + 1] == '\0')
		return (EXIT_FAILURE);
	if (map[x][y + 1] == '\n')
		return (EXIT_FAILURE);
	if (map[x - 1][y] == '0')
		return (check_walls(data, map, x - 1, y));
	if (map[x + 1][y] == '0')
		return (check_walls(data, map, x + 1, y));
	if (map[x][y - 1] == '0')
		return (check_walls(data, map, x, y - 1));
	if (map[x][y + 1] == '0')
		return (check_walls(data, map, x, y + 1));
	map[x][y] = '0';
	return (EXIT_SUCCESS);
}

static void	restore_map(char **map)
{
	int	x;
	int	y;

	x = -1;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
			if (map[x][y] == '9')
				map[x][y] = '0';
	}
}

int	check_map(t_data *data)
{
	int	x;
	int	y;

	while (data->map[--data->m_len][0] == '\n')
		data->map[data->m_len][0] = '\0';
	data->m_len++;
	if (invalid_char(data, data->map))
		return (EXIT_FAILURE);
	if (!data->p_dir)
		return (EXIT_FAILURE);
	x = -1;
	while (data->map[++x])
	{
		y = -1;
		while (data->map[x][++y])
			if (data->map[x][y] == '0')
				if (check_walls(data, data->map, x, y))
					return (EXIT_FAILURE);
	}
	restore_map(data->map);
	return (EXIT_SUCCESS);
}

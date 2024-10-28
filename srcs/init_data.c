/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince < bince@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:52:52 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/28 14:13:58 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_txtr_imgs(t_data *data)
{
	t_texture	*t;
	int			bpp;
	int			line_l;
	int			endian;
	int			i;

	t = data->texture;
	i = -1;
	while (++i < 4)
	{
		t[i].img = mlx_xpm_file_to_image(data->mlx, t[i].f_name, &t[i].width,
				&t[i].height);
		if (!t[i].img)
			return (EXIT_FAILURE);
		t[i].addr = mlx_get_data_addr(t[i].img, &bpp, &line_l, &endian);
	}
	return (EXIT_SUCCESS);
}

float	get_init_angle(t_data *data)
{
	if (data->p_dir == 'N')
		return (3 * M_PI / 2);
	else if (data->p_dir == 'E')
		return (0);
	else if (data->p_dir == 'S')
		return (M_PI / 2);
	else
		return (M_PI);
}

int	init_game_data(t_data *data)
{
	data->t1 = 0;
	data->p_x = data->start_y * TILE_SIZE + 30;
	data->p_y = data->start_x * TILE_SIZE + 30;
	data->p_a = get_init_angle(data);
	data->walk = 0;
	data->rotate = 0;
	data->side_walk = 0;
	data->fov = M_PI / 4.0;
	data->speed = 0.2;
	return (0);
}

int	init_data(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (ft_putendl_fd("Error\nIn initation of mlx", 2), 1);
	data->win = mlx_new_window(data->mlx, WWIN, HWIN, "cub3d");
	if (!data->win)
		return (ft_putendl_fd("Error\nIn window opening", 2), 1);
	data->img_data = create_new_img(data->mlx);
	if (init_txtr_imgs(data))
		return (ft_putendl_fd("Error\nIn initiation of textures", 2), 1);
	return (EXIT_SUCCESS);
}

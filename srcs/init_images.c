/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince < bince@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:52:52 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/22 15:36:22 by bince            ###   ########.fr       */
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
		t[i].img = mlx_xpm_file_to_image(data->mlx, t[i].f_name, \
										&t[i].width, &t[i].height);
		if (!t[i].img)
			return (EXIT_FAILURE);
		t[i].addr = mlx_get_data_addr(t[i].img, &bpp, &line_l, &endian);
	}
	return (EXIT_SUCCESS);
}

int	init_images(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (ft_putendl_fd("Error\nIn initation of mlx", 2), 1);
	data->window = mlx_new_window(data->mlx, WWIN, HWIN, "CUB3D");
	if (!data->window)
		return (ft_putendl_fd("Error\nIn window opening", 2), 1);
	data->img.img = mlx_new_image(data->mlx, WWIN, HWIN);
	if (!data->img.img)
		return (EXIT_FAILURE);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp, \
									&data->img.line_l, &data->img.endian);
	if (init_txtr_imgs(data))
		return (ft_putendl_fd("Error\nIn initiation of textures", 2), 1);
	return (EXIT_SUCCESS);
}

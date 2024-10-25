/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince < bince@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:22:24 by bince             #+#    #+#             */
/*   Updated: 2024/10/25 15:13:32 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	mlx_put_pixel(t_img_data *img_data, int x, int y, int color)
{
	char	*dst;

	dst = img_data->addr + (y * img_data->line_length + x
			* (img_data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_img_data	create_new_img(void *mlx)
{
	t_img_data	img_data;

	img_data.img = mlx_new_image(mlx, WWIN, HWIN);
	img_data.addr = mlx_get_data_addr(img_data.img, &img_data.bits_per_pixel,
			&img_data.line_length, &img_data.endian);
	return (img_data);
}

int	get_pixel_color(t_texture *texture, int tex_x, int tex_y)
{
	int	bpp;
	int	line_l;
	int	offset;

	bpp = 32;
	line_l = texture->width * (bpp / 8);
	offset = (tex_y * line_l) + (tex_x * (bpp / 8));
	return (*(int *)(texture->addr + offset));
}

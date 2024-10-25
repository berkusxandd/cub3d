#include "../includes/cub3d.h"

void	free_data(t_data *data)
{
	int			i;
	t_texture	*t;

	t = data->texture;
	clean_textures(data->texture);
	ft_free(data->map);
	t = data->texture;
	i = -1;
	while (++i < 4)
		if (t[i].img)
			mlx_destroy_image(data->mlx, t[i].img);
	if (data->win)
	{
		mlx_destroy_image(data->mlx, data->img_data.img);
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
}

#include "../includes/cub3d.h"

int	check_arg(int ac, char **av)
{
	if (ac != 2)
		return (errno = EINVAL, perror("Error\nError in argument!"),
			EXIT_FAILURE);
	if (ft_strncmp(ft_strrchr((av[1]), '.'), ".cub\0", 5))
		return (errno = EINVAL, perror("Error\nInvalid map name!"),
			EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

t_walls	create_walls(float perp_dist)
{
	t_walls	walls;
	walls.line_height = (int)(HWIN / perp_dist);
	walls.draw_start = -walls.line_height / 2 + HWIN / 2;
	walls.draw_end = walls.line_height / 2 + HWIN / 2;
	walls.tex_start = walls.draw_start;
	walls.tex_end = walls.draw_end;
	walls.draw_start = fmax(0, walls.draw_start);
	walls.draw_end = fmin(HWIN - 1, walls.draw_end);
	return (walls);
}

int	render(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img_data.img);
	data->img_data = create_new_img(data->mlx);
	if (data->img_data.img == NULL)
	{
		ft_putstr_fd("Error putting image,\n",1);
		free_data(data);
		exit(EXIT_FAILURE);
	}
	render_scene(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img_data.img, 0, 0);
	return (0);
}

int	game_loop(t_data *g_data)
{
	set_elapsed_time(g_data);
	player_move(g_data);
	player_rotate(g_data);
	render(g_data);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_arg(argc, argv))
		return (EXIT_FAILURE);
	ft_memset(&data, 0, sizeof(t_data));
	if (parser(&data, argv[1]))
		return (free_data(&data), EXIT_FAILURE);
	if (init_data(&data))
		return (free_data(&data), EXIT_FAILURE);
	init_game_data(&data);
	mlx_hook(data.win, 2, 1L << 0, key_press_hook, &data);
	mlx_hook(data.win, 3, 1L << 1, key_release_hook, &data);
	mlx_loop_hook(data.mlx, game_loop, &data);
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, &f_exit, &data);
	mlx_loop(data.mlx);
}

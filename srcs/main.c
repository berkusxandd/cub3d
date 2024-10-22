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

t_walls	create_walls(float perp_dist)
{
	t_walls	walls;

	walls.line_height = (int)(HWIN / perp_dist);
	walls.draw_start = -walls.line_height / 2 + HWIN / 2;
	if (walls.draw_start < 0)
		walls.draw_start = 0;
	walls.draw_end = walls.line_height / 2 + HWIN / 2;
	if (walls.draw_end >= HWIN)
		walls.draw_end = HWIN - 1;
	return (walls);
}

int	pick_px_color(t_ray ray)
{
	if (ray.side == 0)
	{
		return (0xFF0000);
	}
	else if (ray.side == 1)
	{
		return(0x00FF1F);
	}
	else if (ray.side == 2)
	{
		return(0xFFFFFF);
	}
	else
	{
		return(0x1700FF);
	}
}

void	render_walls(t_game_data *g_data)
{
	int		x;
	int		y;
	t_ray	ray;
	t_walls	walls;
	float	perp_dist;
	int		color;

	x = 0;
	while (x < WWIN)
	{
		ray = create_ray(g_data, x);
		if (ray.hit == 1)
		{
			if (ray.side == 0 || ray.side == 1)
				perp_dist = (ray.map_x - ray.ray_x / TILE_SIZE + (1
							- ray.step_x) / 2) / ray.ray_dir_x;
			else
				perp_dist = (ray.map_y - ray.ray_y / TILE_SIZE + (1
							- ray.step_y) / 2) / ray.ray_dir_y;
			walls = create_walls(perp_dist);
			color = pick_px_color(ray);
			y = 0;
			while (y < HWIN)
			{
				if (y > walls.draw_start && y < walls.draw_end)
					mlx_put_pixel(&g_data->img_data, x, y, color);
				else
				{
					if (y > 0 && y < walls.draw_start)
						mlx_put_pixel(&g_data->img_data, x, y, 0x9c96db);
					else
						mlx_put_pixel(&g_data->img_data, x, y, 0x1c7216);
				}
				y++;
			}
		}
		x++;
	}
}
int	render(t_game_data *game_data)
{
	mlx_destroy_image(game_data->mlx, game_data->img_data.img);
	game_data->img_data = create_new_img(game_data->mlx);
	render_walls(game_data);
	mlx_put_image_to_window(game_data->mlx, game_data->win,
		game_data->img_data.img, 0, 0);
	return (0);
}

int	key_press_hook(int keycode, t_game_data *game_data)
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
	// if (keycode == XK_Escape)
	// 	f_exit(data);
	return (0);
}

int	key_release_hook(int keycode, t_game_data *g_data)
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

int	init_game_data(t_game_data *game_data)
{
	game_data->mlx = mlx_init();
	game_data->win = mlx_new_window(game_data->mlx, WWIN, HWIN, "cub3d");
	game_data->img_data = create_new_img(game_data->mlx);
	game_data->t1 = 0;
	game_data->p_x = 256;
	game_data->p_y = 160;
	game_data->p_a = 0;
	game_data->walk = 0;
	game_data->rotate = 0;
	game_data->side_walk = 0;
	game_data->map = malloc(sizeof(char *) * 6);
	//                               when p_a = 0; ------>
	game_data->map[0] = ft_strdup("11111111");
	game_data->map[1] = ft_strdup("10000001");
	game_data->map[2] = ft_strdup("10000001");
	game_data->map[3] = ft_strdup("10000001");
	game_data->map[4] = ft_strdup("11111111");
	game_data->map[5] = NULL;
	game_data->map_height = 5;
	game_data->map_width = 8;
	game_data->fov = 3.14159 / 4.0;
	game_data->cam_depth = 10;
	game_data->speed = 0.2;
	return (0);
}
float	angle_normalizer(float a)
{
	if (a < 0)
		a += 2 * M_PI;
	else if (a > 2 * M_PI)
		a -= 2 * M_PI;
	return (a);
}

void	set_elapsed_time(t_game_data *g_data)
{
	struct timeval	tv;
	long			t2;
	long			t1;

	t2 = g_data->t1;
	gettimeofday(&tv, NULL);
	g_data->t1 = (tv.tv_sec * 1000 + tv.tv_usec / 1000);
	t1 = g_data->t1;
	g_data->delta_time = (t1 - t2);
	printf("dT = %lld\n", g_data->delta_time);
}

int	game_loop(t_game_data *g_data)
{
	render(g_data);
	set_elapsed_time(g_data);
	if (g_data->walk != 0)
	{
		g_data->p_x += g_data->walk * cos(g_data->p_a) * g_data->speed
			* g_data->delta_time;
		g_data->p_y += g_data->walk * sin(g_data->p_a) * g_data->speed
			* g_data->delta_time;
	}
	if (g_data->side_walk != 0)
	{
		g_data->p_x += g_data->side_walk * sin(g_data->p_a) * g_data->speed
			* g_data->delta_time;
		g_data->p_y -= g_data->side_walk * cos(g_data->p_a) * g_data->speed
			* g_data->delta_time;
	}
	if (g_data->rotate == -1)
		g_data->p_a -= 0.005 * g_data->delta_time;
	else if (g_data->rotate == 1)
		g_data->p_a += 0.005 * g_data->delta_time;
	g_data->p_a = angle_normalizer(g_data->p_a);
	return (1);
}

int	main(int argc,char **argv)
{
	t_data data;
	t_game_data	game_data;

	if (init_game_data(&game_data) != 0)
		return (-1);
	if (check_arg(argc, argv))
		return (EXIT_FAILURE);
	memset(&data, 0, sizeof(t_data));  //FT_MEMSET ?
	if (parser(&data, argv[1]))
		return (free_data(&data), EXIT_FAILURE);
	// if (init_images(&data))
	// 	return (free_data(&data), EXIT_FAILURE);
	data.game_data = &game_data;

	mlx_hook(game_data.win, 2, 1L << 0, key_press_hook, &game_data);
	mlx_hook(game_data.win, 3, 1L << 1, key_release_hook, &game_data);
	mlx_loop_hook(game_data.mlx, game_loop, &game_data);
	// mlx_hook(game_data.win, DestroyNotify, StructureNotifyMask, &f_exit, &data);
	mlx_loop(game_data.mlx);
}

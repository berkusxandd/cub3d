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
	if (walls.draw_start < 0)
		walls.draw_start = 0;
	walls.draw_end = walls.line_height / 2 + HWIN / 2;
	if (walls.draw_end >= HWIN)
		walls.draw_end = HWIN - 1;
	return (walls);
}

int get_tex_x(t_data *g_data, t_ray ray, float perp_dist)
{
	float wall_x;
	int tex_x;
	if (ray.side < 2)
		wall_x = ray.ray_y / TILE_SIZE + perp_dist * ray.ray_dir_y;
	else
		wall_x = ray.ray_x / TILE_SIZE + perp_dist * ray.ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (g_data->texture[ray.side].width));
	if (ray.side == 0 || ray.side == 2)
		tex_x = g_data->texture[ray.side].width - tex_x - 1;
	return (tex_x);
}

int get_tex_y(t_data *g_data, t_walls walls, t_ray ray, int y)
{
	int tex_y;

	tex_y = ((y - walls.draw_start) * g_data->texture[ray.side].height)
		/ walls.line_height;
	return (tex_y);
}
void	render_wall_texture(t_data *g_data, int x, int y, t_ray ray,float perp_dist,t_walls walls)
{
	int		tex_x;
	int		tex_y;
	int		color;

	tex_x = get_tex_x(g_data,ray,perp_dist);
	tex_y = get_tex_y(g_data,walls,ray,y);
	color = get_pixel_color(&g_data->texture[ray.side], tex_x, tex_y);
	mlx_put_pixel(&g_data->img_data, x, y, color);
}


void	render_env(t_data *g_data, int x, int y, t_walls walls)
{
	if (y > 0 && y < walls.draw_start)
		mlx_put_pixel(&g_data->img_data, x, y, g_data->texture[C].color);
	else
		mlx_put_pixel(&g_data->img_data, x, y, g_data->texture[F].color);
}

void	render_walls(t_data *g_data)
{
	int		x;
	int		y;
	t_ray	ray;
	t_walls	walls;
	float	perp_dist;

	x = 0;
	while (x < WWIN)
	{
		ray = create_ray(g_data, x);
		if (ray.hit == 1)
		{
			perp_dist = get_perp_dist(g_data, ray);
			walls = create_walls(perp_dist);
			y = 0;
			while (y < HWIN)
			{
				if (y > walls.draw_start && y < walls.draw_end)
					render_wall_texture(g_data, x, y, ray, perp_dist, walls);
				else
					render_env(g_data, x, y, walls);
				y++;
			}
		}
		x++;
	}
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
	render_walls(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img_data.img, 0, 0);
	return (0);
}

void	player_rotate(t_data *g_data)
{
	if (g_data->rotate == -1)
		g_data->p_a -= 0.005 * g_data->delta_time;
	else if (g_data->rotate == 1)
		g_data->p_a += 0.005 * g_data->delta_time;
	g_data->p_a = angle_normalizer(g_data->p_a);
}

int	game_loop(t_data *g_data)
{
	set_elapsed_time(g_data);
	player_move(g_data);
	player_rotate(g_data);
	render(g_data);
	return (1);
}

int	f_exit(t_data *data)
{
	free_data(data);
	exit(EXIT_SUCCESS);
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

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

int get_pixel_color(t_texture *texture, int tex_x, int tex_y)
{
    int bpp = 32;
    int line_l = texture->width * (bpp / 8);
    int offset = (tex_y * line_l) + (tex_x * (bpp / 8));
    return *(int *)(texture->addr + offset);
}

void render_wall_texture(t_data *g_data, int x, int y,t_ray ray, float perp_dist, int draw_start, t_walls walls)
{
	float wall_x;
	int tex_x;
	int tex_y;
	int color;

	if (ray.side < 2)
    	wall_x = ray.ray_y / TILE_SIZE + perp_dist * ray.ray_dir_y;
	else
    	wall_x = ray.ray_x / TILE_SIZE + perp_dist * ray.ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (g_data->texture[ray.side].width));
	tex_y = ((y - draw_start) * g_data->texture[ray.side].height) / walls.line_height;
	if (ray.side == 0 || ray.side == 2)
		tex_x = g_data->texture[ray.side].width - tex_x - 1;
    color = get_pixel_color(&g_data->texture[ray.side], tex_x, tex_y);
	mlx_put_pixel(&g_data->img_data, x, y, color);
}

void render_env(t_data *g_data, int x,int y, t_walls walls)
{
	if (y > 0 && y < walls.draw_start)
        mlx_put_pixel(&g_data->img_data, x, y, g_data->texture[C].color);
    else
        mlx_put_pixel(&g_data->img_data, x, y, g_data->texture[F].color);
}

float get_perp_dist(t_data *g_data, t_ray ray)
{
	float delta_angle;
	float perp_dist;

 	if (ray.side == 0 || ray.side == 1)
        perp_dist = (ray.side_dist_x - ray.delta_dist_x); 
    else
	{
        perp_dist = (ray.side_dist_y - ray.delta_dist_y);
	}
	delta_angle = ray.ray_angle - g_data->p_a;
    if (delta_angle > M_PI)
        delta_angle -= 2 * M_PI;
    else if (delta_angle < -M_PI)
        delta_angle += 2 * M_PI;
    perp_dist = perp_dist * cos(delta_angle);
	return (perp_dist);
}

void render_walls(t_data *g_data)
{
    int     x;
    int     y;
    t_ray   ray;
    t_walls walls;
    float   perp_dist;

    x = 0;
    while (x < WWIN)
    {
        ray = create_ray(g_data, x);
        if (ray.hit == 1)
        {
        	perp_dist = get_perp_dist(g_data,ray);
            walls = create_walls(perp_dist);
            y = 0;
            while (y < HWIN)
            {
                if (y > walls.draw_start && y < walls.draw_end)
                    render_wall_texture(g_data, x, y, ray, perp_dist, walls.draw_start,walls);
                else
					render_env(g_data,x,y,walls);
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
	render_walls(data);
	mlx_put_image_to_window(data->mlx, data->win,
		data->img_data.img, 0, 0);
	return (0);
}

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
	// if (keycode == XK_Escape)
	// 	f_exit(data);
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
float	angle_normalizer(float a)
{
	if (a < 0)
		a += 2 * M_PI;
	else if (a > 2 * M_PI)
		a -= 2 * M_PI;
	return (a);
}

void	set_elapsed_time(t_data *g_data)
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

int is_walking_to_wall(t_data *g_data)
{
	float new_x;
	float new_y;
	//add new_x_map new_y_map and check boundaries
	new_x = g_data->p_x;
	new_y = g_data->p_y;
	new_x += g_data->walk * cos(g_data->p_a) * g_data->speed
			* g_data->delta_time;
	new_y += g_data->walk * sin(g_data->p_a) * g_data->speed
			* g_data->delta_time;

	
	return (g_data->map[(int)(new_y / TILE_SIZE)][(int)(new_x / TILE_SIZE)] == '1');
}

int is_sidewalking_to_wall(t_data *g_data)
{
	float new_x;
	float new_y;
	//add new_x_map new_y_map and check boundaries

	new_x = g_data->p_x;
	new_y = g_data->p_y;
	new_x += g_data->side_walk * sin(g_data->p_a) * g_data->speed
			* g_data->delta_time;
	new_y -= g_data->side_walk * cos(g_data->p_a) * g_data->speed
			* g_data->delta_time;

	return (g_data->map[(int)(new_y / TILE_SIZE)][(int)(new_x / TILE_SIZE)] == '1');
}

int	game_loop(t_data *g_data)
{
	set_elapsed_time(g_data);
	if (g_data->walk != 0)
	{
		if (is_walking_to_wall(g_data) == 0)
		{
		g_data->p_x += g_data->walk * cos(g_data->p_a) * g_data->speed
			* g_data->delta_time;
		g_data->p_y += g_data->walk * sin(g_data->p_a) * g_data->speed
			* g_data->delta_time;
		}
	}
	if (g_data->side_walk != 0)
	{
		if (is_sidewalking_to_wall(g_data) == 0)
		{
		g_data->p_x += g_data->side_walk * sin(g_data->p_a) * g_data->speed
			* g_data->delta_time;
		g_data->p_y -= g_data->side_walk * cos(g_data->p_a) * g_data->speed
			* g_data->delta_time;
		}
	}
	if (g_data->rotate == -1)
		g_data->p_a -= 0.005 * g_data->delta_time;
	else if (g_data->rotate == 1)
		g_data->p_a += 0.005 * g_data->delta_time;
	g_data->p_a = angle_normalizer(g_data->p_a);
	render(g_data);
	return (1);
}

int	main(int argc,char **argv)
{
	t_data data;

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
	//mlx_hook(data.win, DestroyNotify, StructureNotifyMask, &f_exit, &data);
	mlx_loop(data.mlx);
}

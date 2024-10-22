#include "../includes/cub3d.h"

t_ray	create_ray(t_game_data *g_data, int x)
{
	t_ray	ray;

	ray.hit = 0;
	ray.hit_out_of_map = 0;
	ray.ray_angle = angle_normalizer((g_data->p_a - g_data->fov / 2.0) + ((float)x / WWIN)
		* g_data->fov);
	ray.ray_x = g_data->p_x;
	ray.ray_y = g_data->p_y;
	ray.ray_dir_x = cos(ray.ray_angle);
	ray.ray_dir_y = sin(ray.ray_angle);
	ray.delta_dist_x = fabs(1 / ray.ray_dir_x);
	ray.delta_dist_y = fabs(1 / ray.ray_dir_y);
	ray.map_x = (int)(ray.ray_x / TILE_SIZE);
	ray.map_y = (int)(ray.ray_y / TILE_SIZE);
	if (ray.ray_dir_x < 0)
	{
		ray.step_x = -1;
		ray.side_dist_x = (ray.ray_x / TILE_SIZE - ray.map_x)
			* ray.delta_dist_x;
	}
	else
	{
		ray.step_x = 1;
		ray.side_dist_x = ((ray.map_x + 1.0) - ray.ray_x / TILE_SIZE)
			* ray.delta_dist_x;
	}
	if (ray.ray_dir_y < 0)
	{
		ray.step_y = -1;
		ray.side_dist_y = (ray.ray_y / TILE_SIZE - ray.map_y)
			* ray.delta_dist_y;
	}
	else
	{
		ray.step_y = 1;
		ray.side_dist_y = ((ray.map_y + 1.0) - ray.ray_y / TILE_SIZE)
			* ray.delta_dist_y;
	}
	while (ray.hit == 0 && ray.hit_out_of_map != 1)
	{
		if (ray.side_dist_x < ray.side_dist_y)
		{
			ray.side_dist_x += ray.delta_dist_x;
			ray.map_x += ray.step_x;
			ray.side = 0;
			if (ray.ray_angle > M_PI / 2 && ray.ray_angle < 3 * M_PI / 2)
				ray.side = 0;
			else
				ray.side = 1;
		}
		else
		{
			ray.side_dist_y += ray.delta_dist_y;
			ray.map_y += ray.step_y;
			ray.side = 1;
			if (ray.ray_angle > 0 && ray.ray_angle <  M_PI)
				ray.side = 2;
			else
				ray.side = 3;
		}
		if (ray.map_y < g_data->map_height && ray.map_x < g_data->map_width && ray.map_y > 0   //hard coded map boundaries
			&& ray.map_x >= 0)
		{
			if (g_data->map[ray.map_y][ray.map_x] == '1')    /////SEGFAULT
				ray.hit = 1;
		}
		else
			ray.hit_out_of_map = 1;
	}
	return (ray);
}

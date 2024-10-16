#ifndef CUB3D_H
#define CUB3D_H
#include <stdio.h>
#include <mlx.h>
#include <stdlib.h>
#include "../Libft/libft.h"
#include <math.h>
#define TILE_SIZE 64
#define WWIN 1280
#define HWIN 720
#define KEY_W 0x0077
#define KEY_A 0x0061
#define KEY_S 0x0073
#define KEY_D 0x0064
#define KEY_ESC 0xff1b
#ifndef M_PI
#    define M_PI 3.14159265358979323846
#endif

typedef struct s_img_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_img_data;

typedef struct s_game_data
{
	float p_x;
	float p_y;
	double p_a;
	int walk;
	int rotate;
	void *mlx;
	void *win;
	t_img_data img_data;
	int map_height;
	int map_width;
	char **map;
	double fov;
	double speed;
	int cam_depth;
}t_game_data;

typedef struct s_ray
{
		float ray_angle;
        float ray_x;
        float ray_y;
        float ray_dir_x;
        float ray_dir_y;
		float delta_dist_x;
        float delta_dist_y;
        float side_dist_x;
        int map_x;
        int map_y;
        int step_x;
		int step_y;
        float side_dist_y;
		 int hit;
		int hit_out_of_map;
        int side;
}t_ray;

typedef struct s_walls
{
	int line_height;
    int draw_start;
	int draw_end;
	int color;
}t_walls;

t_ray	create_ray(t_game_data *g_data, int x);
float angle_normalizer(float a);
#endif

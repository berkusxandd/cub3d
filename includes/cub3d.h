#ifndef CUB3D_H
#define CUB3D_H
#include <stdio.h>
#include <mlx.h>
#include <stdlib.h>
#include "../libft/libft.h"
# include "../libft/get_next_line.h"
#include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "parser.h"
#define TILE_SIZE 64
#define WWIN 1280
#define HWIN 720
#define KEY_W 0x0077
#define KEY_A 0x0061
#define KEY_S 0x0073
#define KEY_D 0x0064
#define LEFT_ARROW 0xff51
#define RIGHT_ARROW  0xff53
#define KEY_ESC 0xff1b
#include <sys/time.h>
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
	int side_walk;
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
	long long t1;
	long long delta_time;
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

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_l;
	int		endian;
}	t_image;
typedef struct s_data
{
	char		**map;
	t_texture	texture[6];
	int			fd;
	int			m_max;
	int			m_len;
	int			m_width;
	int			floor;
	int			ceiling;
	int			start_x;
	int			start_y;
	int			p_dir;
	void		*mlx;
	void		*window;
	t_image		img;
	t_game_data *game_data;
}				t_data;

int		key_hook(int keycode, t_data *data);
int		f_exit(t_data *data);
void	free_data(t_data *data);
t_ray	create_ray(t_game_data *g_data, int x);
float angle_normalizer(float a);
#endif

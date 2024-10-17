/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:14:36 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/14 17:51:06 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "cub3d.h"

typedef struct s_data	t_data;
typedef enum e_dir
{
	N,
	S,
	W,
	E,
	F,
	C
}			t_dir;

typedef struct e_texture
{
	char	*f_name;
	char	*addr;
	void	*img;
	int		height;
	int		width;
	int		color;
	int		check;
}			t_texture;

int		get_textures(t_data *data);
int		parser(t_data *data, char *f_name);
void	clean_textures(t_texture *texture);
int		ft_atoi_3d(const char *line);
void	ft_free(char **str);
int		check_map(t_data *data);
int		init_images(t_data *data);

#endif

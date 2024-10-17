/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:08:54 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/11 15:47:59 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	ft_atoi_3d(const char *line)
{
	int	rgb[3];
	int	check;
	int	i;

	check = 0;
	i = 0;
	while (line[i] == ' ')
		i++;
	while (line[i])
	{
		if (ft_isdigit(line[i]) && check < 3)
			rgb[check] = (ft_atoi(line + i));
		else
			return (-1);
		if (rgb[check] < 0 || rgb[check++] > 255)
			return (-1);
		while (ft_isdigit(line[i]))
			i++;
		if (line[i++] != ',' && check < 3)
			return (-1);
	}
	if (check != 3)
		return (-1);
	return (create_trgb(0, rgb[0], rgb[1], rgb[2]));
}

void	clean_textures(t_texture *texture)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (texture[i].f_name)
		{
			free(texture[i].f_name);
			texture[i].f_name = NULL;
		}
	}
}

void	ft_free(char **str)
{
	int	i;

	i = -1;
	if (str)
	{
		while (str[++i])
		{
			free(str[i]);
			str[i] = NULL;
		}
		free(str);
		str = NULL;
	}
}

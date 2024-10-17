/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:20:28 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/14 15:26:05 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	verif_textures(t_texture *texture)
{
	int	i;

	i = -1;
	while (++i < 6)
		if (texture->check != 1)
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	floor_ceiling(char *line, t_texture *texture)
{
	texture->check++;
	if (texture->color)
		return (EXIT_FAILURE);
	texture->color = ft_atoi_3d(line);
	if (texture->color == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	check_add_texture(char *line, t_texture *texture)
{
	texture->check++;
	if (texture->f_name)
		return (EXIT_FAILURE);
	while (*line == ' ')
		line++;
	*(ft_strrchr(line, '\n')) = '\0';
	return (texture->f_name = ft_strdup(line), EXIT_SUCCESS);
}

static int	check_textures(char *line, t_data *data)
{
	if (!ft_strncmp("NO ", line, 3))
		return (check_add_texture(line + 3, &data->texture[N]));
	else if (!ft_strncmp("SO ", line, 3))
		return (check_add_texture(line + 3, &data->texture[S]));
	else if (!ft_strncmp("WE ", line, 3))
		return (check_add_texture(line + 3, &data->texture[W]));
	else if (!ft_strncmp("EA ", line, 3))
		return (check_add_texture(line + 3, &data->texture[E]));
	else if (!ft_strncmp("F ", line, 2))
		return (floor_ceiling(line + 2, &data->texture[F]));
	else if (!ft_strncmp("C ", line, 2))
		return (floor_ceiling(line + 2, &data->texture[C]));
	return (EXIT_FAILURE);
}

int	get_textures(t_data *data)
{
	int		i;
	char	*line;

	line = get_next_line(data->fd);
	if (!line)
		return (EXIT_FAILURE);
	i = 0;
	while (line && i < 6)
	{
		if (*line != '\n')
		{
			if (check_textures(line, data))
				return (free(line), clean_textures(data->texture), 1);
			i++;
		}
		free(line);
		if (i != 6)
			line = get_next_line(data->fd);
	}
	if (verif_textures(data->texture))
		return (clean_textures(data->texture), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

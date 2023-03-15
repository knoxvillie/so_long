/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:08:35 by kfaustin          #+#    #+#             */
/*   Updated: 2023/03/14 22:17:51 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**read_map(t_root *root, int fd)
{
	int		i;
	char	*line;
	char	**map;

	i = 0;
	map = (char **)malloc(sizeof(char *) * (root->column + 1));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map[i++] = ft_strtrim(line, "\n");
		free (line);
	}
	free (line);
	map[i] = NULL;
	return (map);
}

int	ft_line_count(int fd)
{
	int		size;
	char	*line;

	size = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		size++;
		free (line);
	}
	free (line);
	return (size);
}

static void	ft_load_map_aux(t_root *root, char pixel)
{
	if (pixel == '1')
		mlx_put_image_to_window(root->m_ptr, root->w_ptr,
			root->wall, root->x, root->y);
	else if (pixel == '0')
		mlx_put_image_to_window(root->m_ptr, root->w_ptr,
			root->floor, root->x, root->y);
	else if (pixel == 'E')
		mlx_put_image_to_window(root->m_ptr, root->w_ptr,
			root->scape, root->x, root->y);
	else if (pixel == 'P')
		mlx_put_image_to_window(root->m_ptr, root->w_ptr,
			root->player_r, root->x, root->y);
	else
		mlx_put_image_to_window(root->m_ptr, root->w_ptr,
			root->collect, root->x, root->y);
}

void	ft_load_map(t_root *root)
{
	int		i;
	int		j;
	char	pixel;

	j = -1;
	while (++j < root->column)
	{
		i = -1;
		while (++i < root->line)
		{
			pixel = root->map[j][i];
			ft_load_map_aux(root, pixel);
			root->x += DIM;
		}
		root->x = 0;
		root->y += DIM;
	}
}

void	ft_load_window(t_root *root, char *file)
{
	int		fd;

	root->x = 0;
	root->y = 0;
	fd = ft_check_fd(root, file);
	root->map = read_map(root, fd);
	ft_check_rectangle_map(root);
	ft_check_valid_map(root);
	ft_check_map_elements(root);
	ft_check_valid_path(root, 0);
	ft_free_2d_array(root->mp);
	ft_check_valid_path(root, 1);
	ft_check_and_init_wind(root);
	ft_load_map(root);
	close (fd);
}

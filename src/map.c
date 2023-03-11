/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:08:35 by kfaustin          #+#    #+#             */
/*   Updated: 2023/03/11 15:18:51 by kfaustin         ###   ########.fr       */
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

void	ft_load_map(t_root *root)
{
	int		i;
	int		j;
	char	pixel;

	j = 0;
	while (j < root->column)
	{
		i = 0;
		while (i < root->line)
		{
			pixel = root->map[j][i];
			if (pixel == '1')
				mlx_put_image_to_window(root->m_ptr, root->w_ptr, root->wall, root->x, root->y);
			else if (pixel == '0')
				mlx_put_image_to_window(root->m_ptr, root->w_ptr, root->floor, root->x, root->y);
			else if (pixel == 'E')
				mlx_put_image_to_window(root->m_ptr, root->w_ptr, root->scape, root->x, root->y);
			else if (pixel == 'P')
			{
				root->player_x = i;
				root->player_y = j;
				mlx_put_image_to_window(root->m_ptr, root->w_ptr, root->playerR, root->x, root->y);
			}
			else if (pixel == 'C')
				mlx_put_image_to_window(root->m_ptr, root->w_ptr, root->collect, root->x, root->y);
			root->x += DIM;
			i++;
		}
		root->x = 0;
		root->y += DIM;
		j++;
	}
}

void	ft_load_window(t_root *root, char *file)
{
	int		fd;

	root->x = 0;
	root->y = 0;
	fd = ft_check_fd(file);
	root->map = read_map(root, fd);
	ft_check_rectangle_map(root);
	ft_check_valid_map(root);
	ft_check_map_elements(root);
	ft_load_map(root);
	ft_check_valid_path(root);
	close (fd);
}

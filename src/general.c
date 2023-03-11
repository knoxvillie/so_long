/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:27:10 by kfaustin          #+#    #+#             */
/*   Updated: 2023/03/11 16:49:31 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free_and_close(int fd, char *str)
{
	free (str);
	close (fd);
}

void	ft_count_map_elements(t_root *root)
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
			if (pixel == 'P')
				root->start_point++;
			else if (pixel == 'C')
				root->colec_point++;
			else if (pixel == 'E')
				root->exit_point++;
			i++;
		}
		j++;
	}
}

void	ft_rotate_player_sprite(t_root *root, int to_x, int to_y)
{
	if ((root->player_x < to_x ) || (root->player_y < to_y))
	{
		mlx_put_image_to_window(root->m_ptr, root->w_ptr, root->playerR, to_x * DIM, to_y * DIM);
		return ;
	}
	if (root->player_y > to_y)
	{
		mlx_put_image_to_window(root->m_ptr, root->w_ptr, root->playerB, to_x * DIM, to_y * DIM);
		return ;
	}
	if (root->player_x > to_x)
	{
		mlx_put_image_to_window(root->m_ptr, root->w_ptr, root->playerL, to_x * DIM, to_y * DIM);
		return ;
	}
}

char	**ft_dup_2d_array(t_root *root)
{
	int		j;
	int		i;
	char	**map_dup;
	char	*line;

	map_dup = (char **)malloc(sizeof(char *) * (root->column + 1));
	j = 0;
	while (j < root->column)
	{
		i = 0;
		line = (char *)malloc(sizeof(char) * (root->line + 1));
		while (i < root->line)
		{
			line[i] = root->map[j][i];
			i++;
		}
		line[i] = '\0';
		ft_fill_wall_escape(&line);
		map_dup[j++] = line;
	}
	map_dup[j] = NULL;
	return (map_dup);
}

void	ft_flood_fill(t_root *root, int x, int y, char *elements)
{
	if (x < 0 || x >= root->line || y < 0 || y >= root->column)
		return ;
	if (!ft_strchr(elements, root->mp[y][x]))
		return ;
	root->mp[y][x] = root->fill;
	ft_flood_fill(root, (x + 1), y, elements);
	ft_flood_fill(root, (x - 1), y, elements);
	ft_flood_fill(root, x, (y + 1), elements);
	ft_flood_fill(root, x, (y - 1), elements);
}

void	ft_print_map(char **map, int x, int y)
{
	int	i;
	int	j;

	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			ft_printf("%c", map[j][i]);
			i++;
		}
		ft_printf("\n");
		j++;
	}
	ft_printf("\n");
}

void	ft_fill_wall_escape(char **str)
{
	int	i;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == '1' || (*str)[i] == 'E')
			(*str)[i] = 'W';
		i++;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:27:10 by kfaustin          #+#    #+#             */
/*   Updated: 2023/03/14 22:08:40 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_rotate_player_sprite(t_root *root, int to_x, int to_y)
{
	if ((root->player_x < to_x) || (root->player_y < to_y))
	{
		mlx_put_image_to_window(root->m_ptr, root->w_ptr,
			root->player_r, to_x * DIM, to_y * DIM);
		return ;
	}
	if (root->player_y > to_y)
	{
		mlx_put_image_to_window(root->m_ptr, root->w_ptr,
			root->player_b, to_x * DIM, to_y * DIM);
		return ;
	}
	if (root->player_x > to_x)
	{
		mlx_put_image_to_window(root->m_ptr, root->w_ptr,
			root->player_l, to_x * DIM, to_y * DIM);
		return ;
	}
}

void	ft_flood_fill(t_root *root, int x, int y, char *elements)
{
	if (x < 0 || x >= root->line || y < 0 || y >= root->column)
		return ;
	if (root->mp[y][x] == root->fill)
		return ;
	if (!ft_strchr(elements, root->mp[y][x]))
		return ;
	root->mp[y][x] = root->fill;
	ft_flood_fill(root, (x + 1), y, elements);
	ft_flood_fill(root, (x - 1), y, elements);
	ft_flood_fill(root, x, (y + 1), elements);
	ft_flood_fill(root, x, (y - 1), elements);
}

void	ft_count_map_elements(t_root *root)
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
			ft_check_unknown(root, pixel);
			if (pixel == 'P')
				ft_player_coord(root, i, j);
			else if (pixel == 'C')
				root->colec_point++;
			else if (pixel == 'E')
				ft_scape_coord(root, i, j);
		}
	}
}

void	ft_fill_wall_escape(char **str, int select)
{
	int	i;

	i = 0;
	while ((*str)[i])
	{
		if (!select)
		{
			if ((*str)[i] == '1' || (*str)[i] == 'E')
				(*str)[i] = 'W';
		}
		else
		{
			if ((*str)[i] == '1')
				(*str)[i] = 'W';
		}
		i++;
	}
}

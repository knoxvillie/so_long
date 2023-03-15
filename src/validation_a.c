/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:34:29 by kfaustin          #+#    #+#             */
/*   Updated: 2023/03/14 22:19:02 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_check_valid_path(t_root *root, int select)
{
	int	i;
	int	j;

	root->fill = 'X';
	root->mp = ft_dup_2d_array(root, select);
	if (!select)
		ft_flood_fill(root, root->player_x, root->player_y, "P0C");
	else
		ft_flood_fill(root, root->e_x, root->e_y, "P0CE");
	j = -1;
	while (++j < root->column)
	{
		i = -1;
		while (++i < root->line)
		{
			if (root->mp[j][i] != 'W' && root->mp[j][i] != 'X')
			{
				ft_putstr_fd("Error\nThe map doesn't have a valid path\n", 2);
				ft_destroy_root(root, 1);
			}
		}
	}
}

void	ft_check_map_elements(t_root *root)
{
	ft_count_map_elements(root);
	if (root->start_point != 1)
	{
		ft_putstr_fd("Error\n The number of starting positions must be 1\n", 2);
		ft_destroy_root(root, 1);
	}
	if (root->exit_point != 1)
	{
		ft_putstr_fd("Error\n The number of exits must be 1\n", 2);
		ft_destroy_root(root, 1);
	}
	if (root->colec_point < 1)
	{
		ft_putstr_fd("Error\n Collectible must be at least 1\n", 2);
		ft_destroy_root(root, 1);
	}
}

void	ft_check_rectangle_map(t_root *root)
{
	int	len;
	int	i;

	i = 0;
	len = (int)ft_strlen(root->map[i]);
	while (root->map[++i])
	{
		if (len != (int)ft_strlen(root->map[i]))
		{
			ft_putstr_fd("Error\n Invalid map. Not rectangle\n", 2);
			ft_destroy_root(root, 1);
			exit (1);
		}
	}
}

void	ft_check_valid_map(t_root *root)
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
			if ((((j == 0) || (j == root->column - 1)) && pixel != '1')
				|| (((i == 0) || (i == root->line - 1)) && pixel != '1'))
			{
				ft_putstr_fd("Error\n Invalid map. Not surrounded by walls\n", 2);
				ft_destroy_root(root, 1);
				exit (1);
			}
		}
	}
}

void	ft_check_map_name(char *file, const char *extension)
{
	int	len_file;
	int	len_ext;
	int	i;

	len_file = ((int)ft_strlen(file));
	len_ext = ((int)ft_strlen(extension));
	i = -1;
	while (++i < 4)
	{
		if (file[--len_file] != extension[--len_ext])
		{
			ft_putstr_fd("Error\n Invalid map extension.\n", 2);
			exit (1);
		}
	}
}

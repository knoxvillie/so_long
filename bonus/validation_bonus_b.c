/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_bonus_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:34:38 by kfaustin          #+#    #+#             */
/*   Updated: 2023/03/13 14:00:31 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_check_fd(t_root *root, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		close (fd);
		ft_putstr_fd("Error\n Invalid fd! File doesn't exit\n", 2);
		ft_destroy_root(root, 1);
	}
	return (fd);
}

void	ft_check_abs_xy(t_root *root, char *file)
{
	char	*line;
	int		fd;

	fd = ft_check_fd(root, file);
	line = get_next_line(fd);
	if (ft_strlen(line) < 3)
	{
		ft_putstr_fd("Error\n Invalid map x dimension\n", 2);
		ft_destroy_mlx(root, 1);
	}
	root->line = (int)ft_strlen(line) - 1;
	free (line);
	root->column = ft_line_count(fd) + 1;
	if (root->column < 2)
	{
		ft_putstr_fd("Error\n Invalid map y dimension\n", 2);
		ft_destroy_mlx(root, 1);
	}
	close (fd);
}

void	ft_check_unknown(t_root *root, char pixel)
{
	if (!ft_strchr("PEC10H", pixel))
	{
		ft_putstr_fd("Error\n Unknown map element\n", 2);
		ft_destroy_root(root, 1);
	}
}

void	ft_player_coord(t_root *root, int i, int j)
{
	root->player_x = i;
	root->player_y = j;
	root->start_point++;
}

void	ft_scape_coord(t_root *root, int i, int j)
{
	root->e_x = i;
	root->e_y = j;
	root->exit_point++;
}

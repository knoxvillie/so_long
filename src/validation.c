/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:08:27 by kfaustin          #+#    #+#             */
/*   Updated: 2023/03/09 23:36:12 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_validation(t_root *root, char *file, const char *extension)
{
	ft_check_map_name(file, extension);
	ft_check_and_init_mlx(root);
	ft_check_abs_xy(root, file);
	ft_check_and_init_wind(root);
	ft_check_image(root);
}

void	*ft_load_image(t_root *root, char *file)
{
	void	*image;

	image = mlx_xpm_file_to_image(root->m_ptr, file, &root->x, &root->y);
	if (!image)
	{
		ft_putstr_fd("Error: \"", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd("\" Failed to load\n", 2);
		ft_destroy_root(root);
	}
	return (image);
}

void	ft_check_image(t_root *root)
{
	root->wall = ft_load_image(root, WALL);
	root->floor = ft_load_image(root, FLOOR);
	root->player = ft_load_image(root, PLAYER);
	root->enemy = ft_load_image(root, ENEMY);
}

int	ft_check_fd(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		close (fd);
		ft_putstr_fd("Error: Invalid file descriptor!\n", 2);
		exit (1);
	}
	return (fd);
}

void	ft_check_abs_xy(t_root *root, char *file)
{
	char	*line;
	int		fd;

	fd = ft_check_fd(file);
	line = get_next_line(fd);
	if (ft_strlen(line) < 3)
	{
		ft_putstr_fd("Error: Invalid map x dimension\n", 2);
		ft_destroy_mlx(root);
	}
	root->abs_x = (int)ft_strlen(line) - 1;
	free (line);
	root->abs_y = ft_line_count(fd) + 1;
	if (root->abs_y < 2)
	{
		ft_putstr_fd("Error: Invalid map y dimension\n", 2);
		ft_destroy_mlx(root);
	}
	close (fd);
}

void	ft_check_and_init_mlx(t_root *root)
{
	root->m_ptr = mlx_init();
	if (!root->m_ptr)
	{
		ft_putstr_fd("Error: Failed to start mlx_ptr\n", 2);
		ft_destroy_mlx(root);
	}
}

void	ft_check_and_init_wind(t_root *root)
{
	root->w_ptr = mlx_new_window(root->m_ptr, root->abs_x * DIM, root->abs_y * DIM, TITLE);
	if (!root->w_ptr)
	{
		ft_putstr_fd("Error: Failed to start win_ptr\n", 2);
		mlx_destroy_window(root->m_ptr, root->w_ptr);
		ft_destroy_mlx(root);
	}
}

void	ft_check_map_name(char *file, const char *extension)
{
	int	len_file;
	int len_ext;
	int i;

	len_file = ((int)ft_strlen(file));
	len_ext = ((int)ft_strlen(extension));
	i = -1;
	while (++i < 4)
	{
		if (file[--len_file] != extension[--len_ext])
		{
			ft_putstr_fd("Error: Invalid map extension.\n", 2);
			exit (1);
		}
	}
}

void	ft_check_valid_map(t_root *root)
{
	int		i;
	int		j;
	char	pixel;

	j = 0;
	while (j < root->abs_y)
	{
		i = 0;
		while (i < root->abs_x)
		{
			pixel = root->map[j][i];
			if ((((j == 0) || (j == root->abs_y - 1)) && pixel != '1')
				|| (((i == 0) || (i == root->abs_x - 1)) && pixel != '1'))
			{
				ft_putstr_fd("Error: Invalid map. Not surrounded by walls\n", 2);
				ft_destroy_root(root);
				exit (1);
			}
			i++;
		}
		j++;
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
			ft_putstr_fd("Error: Invalid map. Not rectangle\n", 2);
			ft_destroy_root(root);
			exit (1);
		}
	}
}
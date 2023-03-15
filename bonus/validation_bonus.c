/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:08:27 by kfaustin          #+#    #+#             */
/*   Updated: 2023/03/15 11:01:54 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_validation(t_root *root, char *file, const char *extension)
{
	ft_check_map_name(file, extension);
	ft_check_and_init_mlx(root);
	ft_check_abs_xy(root, file);
	ft_check_image(root);
}

void	*ft_load_image(t_root *root, char *file)
{
	void	*image;

	image = mlx_xpm_file_to_image(root->m_ptr, file, &root->x, &root->y);
	if (!image)
	{
		ft_putstr_fd("Error\n Failed to load an image: FILE ", 2);
		ft_printf("%s\n", file);
		ft_destroy_root(root, 1);
	}
	return (image);
}

void	ft_check_image(t_root *root)
{
	root->wall = ft_load_image(root, WALL);
	root->floor = ft_load_image(root, FLOOR);
	root->player_r = ft_load_image(root, PLAYERR);
	root->player_l = ft_load_image(root, PLAYERL);
	root->player_b = ft_load_image(root, PLAYERB);
	root->enemy = ft_load_image(root, ENEMY);
	root->enemy_r = ft_load_image(root, ENEMYR);
	root->enemy_b = ft_load_image(root, ENEMYB);
	root->scape = ft_load_image(root, SCAPE);
	root->scape1 = ft_load_image(root, SCAPE1);
	root->scape2 = ft_load_image(root, SCAPE2);
	root->collect = ft_load_image(root, COLLECT);
	root->img = ft_load_image(root, WALLONE);
}

void	ft_check_and_init_mlx(t_root *root)
{
	root->m_ptr = mlx_init();
	if (!root->m_ptr)
	{
		ft_putstr_fd("Error\n Failed to start mlx_ptr\n", 2);
		ft_destroy_mlx(root, 1);
	}
}

void	ft_check_and_init_wind(t_root *root)
{
	root->w_ptr = mlx_new_window(root->m_ptr, root->line * DIM,
			root->column * DIM, TITLE);
	if (!root->w_ptr)
	{
		ft_putstr_fd("Error\n Failed to start win_ptr\n", 2);
		ft_destroy_root(root, 1);
	}
}

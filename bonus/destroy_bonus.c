/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:13:28 by kfaustin          #+#    #+#             */
/*   Updated: 2023/03/15 10:54:27 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_kill_player(t_root *root)
{
	ft_putstr_fd("Player died!\n", 2);
	ft_destroy_root(root, 0);
}

void	ft_destroy_mlx(t_root *root, int flag)
{
	mlx_destroy_display(root->m_ptr);
	free (root->m_ptr);
	exit (flag);
}

void	ft_destroy_enemy(t_root *root)
{
	if (root->enemy)
		mlx_destroy_image(root->m_ptr, root->enemy);
	if (root->enemy_r)
		mlx_destroy_image(root->m_ptr, root->enemy_r);
	if (root->enemy_b)
		mlx_destroy_image(root->m_ptr, root->enemy_b);
	if (root->scape1)
		mlx_destroy_image(root->m_ptr, root->scape1);
	if (root->scape2)
		mlx_destroy_image(root->m_ptr, root->scape2);
}

void	ft_destroy_root(t_root *root, int flag)
{
	ft_free_2d_array(root->map);
	ft_free_2d_array(root->mp);
	if (root->wall)
		mlx_destroy_image(root->m_ptr, root->wall);
	if (root->floor)
		mlx_destroy_image(root->m_ptr, root->floor);
	if (root->scape)
		mlx_destroy_image(root->m_ptr, root->scape);
	ft_destroy_enemy(root);
	if (root->player_r)
		mlx_destroy_image(root->m_ptr, root->player_r);
	if (root->player_l)
		mlx_destroy_image(root->m_ptr, root->player_l);
	if (root->player_b)
		mlx_destroy_image(root->m_ptr, root->player_b);
	if (root->collect)
		mlx_destroy_image(root->m_ptr, root->collect);
	if (root->img)
		mlx_destroy_image(root->m_ptr, root->img);
	if (root->w_ptr)
		mlx_destroy_window(root->m_ptr, root->w_ptr);
	ft_destroy_mlx(root, flag);
}

void	ft_free_2d_array(char **map)
{
	int	i;

	if (!map)
	{
		free (map);
		return ;
	}
	i = 0;
	while (map[i])
		free (map[i++]);
	free (map[i]);
	free (map);
}

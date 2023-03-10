/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:13:28 by kfaustin          #+#    #+#             */
/*   Updated: 2023/03/10 13:15:35 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_destroy_mlx(t_root *root, int flag)
{
	mlx_destroy_display(root->m_ptr);
	free (root->m_ptr);
	exit (flag);
}

void	ft_destroy_root(t_root *root, int flag)
{
	ft_free_2d_array(root->map);
	if (root->wall)
		mlx_destroy_image(root->m_ptr ,root->wall);
	if (root->floor)
		mlx_destroy_image(root->m_ptr ,root->floor);
	if (root->enemy)
		mlx_destroy_image(root->m_ptr ,root->enemy);
	if (root->player)
		mlx_destroy_image(root->m_ptr ,root->player);
	if (root->colect)
		mlx_destroy_image(root->m_ptr ,root->colect);
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
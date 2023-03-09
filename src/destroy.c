/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:13:28 by kfaustin          #+#    #+#             */
/*   Updated: 2023/03/09 23:24:38 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_destroy_mlx(t_root *root)
{
	mlx_destroy_display(root->m_ptr);
	free (root->m_ptr);
	exit (1);
}

void	ft_destroy_root(t_root *root)
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
	mlx_destroy_window(root->m_ptr, root->w_ptr);
	ft_destroy_mlx(root);
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:13:28 by kfaustin          #+#    #+#             */
/*   Updated: 2023/03/11 14:55:06 by kfaustin         ###   ########.fr       */
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
	ft_free_2d_array(root->mp);
	if (root->wall)
		mlx_destroy_image(root->m_ptr ,root->wall);
	if (root->floor)
		mlx_destroy_image(root->m_ptr ,root->floor);
	if (root->scape)
		mlx_destroy_image(root->m_ptr ,root->scape);
	if (root->playerR)
		mlx_destroy_image(root->m_ptr ,root->playerR);
	if (root->playerL)
		mlx_destroy_image(root->m_ptr ,root->playerL);
	if (root->playerB)
		mlx_destroy_image(root->m_ptr ,root->playerB);
	if (root->collect)
		mlx_destroy_image(root->m_ptr ,root->collect);
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
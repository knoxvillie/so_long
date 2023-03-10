/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:27:10 by kfaustin          #+#    #+#             */
/*   Updated: 2023/03/09 14:41:06 by kfaustin         ###   ########.fr       */
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
	if ((root->p_x < to_x ) || (root->p_y < to_y))
	{
		mlx_put_image_to_window(root->m_ptr, root->w_ptr, root->playerR, to_x * DIM, to_y * DIM);
		return ;
	}
	if (root->p_y > to_y)
	{
		mlx_put_image_to_window(root->m_ptr, root->w_ptr, root->playerB, to_x * DIM, to_y * DIM);
		return ;
	}
	if (root->p_x > to_x)
	{
		mlx_put_image_to_window(root->m_ptr, root->w_ptr, root->playerL, to_x * DIM, to_y * DIM);
		return ;
	}
}
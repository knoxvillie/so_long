/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:36:14 by kfaustin          #+#    #+#             */
/*   Updated: 2023/03/10 21:55:09 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_valid_move(t_root *root, int to_x, int to_y)
{
	char	pixel;

	pixel = root->map[to_y][to_x];
	if (pixel == '1')
		return (0);
	if (pixel == 'E' && root->colec_point != 0)
		return (0);
	if (pixel == 'E' && root->colec_point == 0)
		return (-1);
	if (pixel == 'C')
		root->colec_point--;
	return (1);
}

int	ft_move_player(t_root *root, int to_x, int to_y)
{
	int	flag;

	flag = ft_check_valid_move(root, to_x, to_y);
	if (!flag)
		return (0);
	root->map[root->p_y][root->p_x] = '0';
	mlx_put_image_to_window(root->m_ptr, root->w_ptr, root->floor, root->p_x * DIM, root->p_y * DIM);
	root->map[to_y][to_x] = 'P';
	ft_rotate_player_sprite(root, to_x, to_y);
	root->p_x = to_x;
	root->p_y = to_y;
	return (flag);
}
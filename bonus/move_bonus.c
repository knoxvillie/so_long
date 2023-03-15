/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:36:14 by kfaustin          #+#    #+#             */
/*   Updated: 2023/03/14 12:50:52 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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
	if (pixel == 'H')
		ft_kill_player(root);
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
	root->map[root->player_y][root->player_x] = '0';
	mlx_put_image_to_window(root->m_ptr, root->w_ptr, root->floor,
		root->player_x * DIM, root->player_y * DIM);
	root->map[to_y][to_x] = 'P';
	ft_rotate_player_sprite(root, to_x, to_y);
	root->player_x = to_x;
	root->player_y = to_y;
	return (flag);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:31:23 by kfaustin          #+#    #+#             */
/*   Updated: 2023/03/14 13:57:56 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_check_possible_move(t_root *root, int to_x, int to_y, void *image)
{
	char	pixel;

	pixel = root->map[to_y][to_x];
	if (pixel == 'P')
		ft_kill_player(root);
	if (pixel == '1' || pixel == 'E' || pixel == 'C' || pixel == 'H')
		return (0);
	root->map[to_y][to_x] = 'H';
	mlx_put_image_to_window(root->m_ptr, root->w_ptr,
		image, to_x * DIM, to_y * DIM);
	return (1);
}

void	ft_do_enemy_move(t_root *root, int x, int y, int move)
{
	int	moved;

	moved = 0;
	if (move == 0)
		moved = ft_check_possible_move(root, x, (y - 1), root->enemy_b);
	else if (move == 1)
		moved = ft_check_possible_move(root, x, (y + 1), root->enemy);
	else if (move == 2)
		moved = ft_check_possible_move(root, (x - 1), y, root->enemy_r);
	else if (move == 3)
		moved = ft_check_possible_move(root, (x + 1), y, root->enemy);
	if (moved)
	{
		root->map[y][x] = '0';
		mlx_put_image_to_window(root->m_ptr, root->w_ptr,
			root->floor, x * DIM, y * DIM);
	}
}

void	ft_enemy_move(t_root *root)
{
	int	rand_move;
	int	i;
	int	j;

	j = -1;
	while (++j < root->column)
	{
		i = -1;
		while (++i < root->line)
		{
			if (root->map[j][i] == 'H')
			{
				rand_move = rand() % 4;
				ft_do_enemy_move(root, i, j, rand_move);
			}
		}
	}
}

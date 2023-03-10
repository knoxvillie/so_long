/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:39:49 by kfaustin          #+#    #+#             */
/*   Updated: 2023/03/10 21:55:09 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_close_root_event(t_root *root)
{
	ft_destroy_root(root, 0);
	return (1);
}

int		ft_key_event(int keycode, t_root *root)
{
	int	moved;

	moved = 0;
	if (keycode == ESC)
		ft_close_root_event(root);
	else if (keycode == W)
		moved = ft_move_player(root, root->p_x, root->p_y - 1);
	else if (keycode == S)
		moved = ft_move_player(root, root->p_x, root->p_y + 1);
	else if (keycode == A)
		moved = ft_move_player(root, root->p_x - 1, root->p_y);
	else if (keycode == D)
		moved = ft_move_player(root, root->p_x + 1, root->p_y);
	if (moved)
	{
		ft_printf("Moves: %d\n", ++root->moves);
		if (moved == -1)
			ft_close_root_event(root);
	}
	return (moved);
}
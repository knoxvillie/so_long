/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:13:42 by kfaustin          #+#    #+#             */
/*   Updated: 2023/03/15 10:53:35 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	ft_initialize_root(t_root *root)
{
	root->w_ptr = (void *)0;
	root->x = 0;
	root->y = 0;
	root->map = NULL;
	root->wall = (void *)0;
	root->floor = (void *)0;
	root->scape = (void *)0;
	root->scape1 = (void *)0;
	root->scape2 = (void *)0;
	root->enemy = (void *)0;
	root->enemy_r = (void *)0;
	root->enemy_b = (void *)0;
	root->player_r = (void *)0;
	root->player_l = (void *)0;
	root->player_b = (void *)0;
	root->collect = (void *)0;
	root->img = (void *)0;
	root->moves = 0;
	root->start_point = 0;
	root->colec_point = 0;
	root->exit_point = 0;
	root->mp = NULL;
}

int	main(int argc, char **argv)
{
	t_root	root;
	char	*file;

	if (argc == 2)
	{
		srand(time(0));
		file = argv[1];
		ft_initialize_root(&root);
		ft_validation(&root, file, ".ber");
		ft_load_window(&root, file);
		mlx_hook(root.w_ptr, 17, 0, ft_close_root_event, &root);
		mlx_hook(root.w_ptr, 3, (1L << 1), ft_key_event, &root);
		mlx_loop_hook(root.m_ptr, ft_event_frames, &root);
		mlx_loop(root.m_ptr);
	}
	return (0);
}

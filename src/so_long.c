/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 09:45:34 by kfaustin          #+#    #+#             */
/*   Updated: 2023/03/11 14:54:44 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_initialize_root(t_root *root)
{
	root->x = 0;
	root->y = 0;
	root->map = NULL;
	root->wall = (void *)0;
	root->floor = (void *)0;
	root->scape = (void *)0;
	root->playerR = (void *)0;
	root->playerL = (void *)0;
	root->playerB = (void *)0;
	root->collect = (void *)0;
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
		file = argv[1];
		ft_initialize_root(&root);
		ft_validation(&root, file, ".ber");
		ft_load_window(&root, file);
		mlx_hook(root.w_ptr, 17, 0, ft_close_root_event, &root);
		mlx_hook(root.w_ptr, KeyPress, KeyPressMask, ft_key_event, &root);
		mlx_loop(root.m_ptr);
	}
	return (0);
}

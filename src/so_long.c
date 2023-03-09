/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 09:45:34 by kfaustin          #+#    #+#             */
/*   Updated: 2023/03/09 23:33:11 by kfaustin         ###   ########.fr       */
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
	root->enemy = (void *)0;
	root->player = (void *)0;
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
		mlx_hook(root.m_ptr, KeyPress, KeyPressMask, ft_key_event(), &root);
		mlx_loop(root.m_ptr);
	}
	return (0);
}

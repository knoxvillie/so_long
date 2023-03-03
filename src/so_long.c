/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 09:45:34 by kfaustin          #+#    #+#             */
/*   Updated: 2023/03/03 13:39:51 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_mlx_buffer_null(void *buffer)
{
	if (buffer == NULL)
	{
		free (buffer);
		exit (0);
	}
}

int	main(int argc, char **argv)
{
	t_data	root;

	(void)argc;
	if (argc != 2)
	{
		ft_putstr_fd("Invalid map file\n", 1);
		return (0);
	}
	root.mlx_ptr = mlx_init();
	ft_mlx_buffer_null(root.mlx_ptr);
	root.win_ptr = mlx_new_window(root.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "WOLFGANG");
	ft_mlx_buffer_null(root.win_ptr);
	root.wall = mlx_xpm_file_to_image(root.mlx_ptr, WALL, &root.x, &root.y);
	ft_mlx_buffer_null(root.wall);
	root.floor = mlx_xpm_file_to_image(root.mlx_ptr, FLOOR, &root.x, &root.y);
	mlx_loop(root.mlx_ptr);
	mlx_destroy_window(root.mlx_ptr, root.win_ptr);
	mlx_destroy_display(root.mlx_ptr);
	free (root.mlx_ptr);
	return (0);
}

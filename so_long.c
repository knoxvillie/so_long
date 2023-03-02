/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 09:45:34 by kfaustin          #+#    #+#             */
/*   Updated: 2023/03/02 14:58:04 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"
#include <stdio.h>

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
	t_data	p;

	(void)argc;
	(void)argv;

	p.mlx_ptr = mlx_init();
	ft_mlx_buffer_null(p.mlx_ptr);
	p.win_ptr = mlx_new_window(p.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "WOLFGANG");
	ft_mlx_buffer_null(p.win_ptr);
	p.sprite = mlx_xpm_file_to_image(p.mlx_ptr, SPRITE, &p.x, &p.y);
	ft_mlx_buffer_null(p.sprite);
	ft_putnbr_fd(p.x, 1);
	ft_putnbr_fd(p.y, 1);
	mlx_put_image_to_window(p.mlx_ptr, p.win_ptr, p.sprite, 0, 0);
	//mlx_loop(p.mlx_ptr);
	mlx_destroy_window(p.mlx_ptr, p.win_ptr);
	mlx_destroy_display(p.mlx_ptr);
	free (p.mlx_ptr);
	return (0);
}

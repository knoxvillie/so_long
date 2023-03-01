/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:24:57 by kfaustin          #+#    #+#             */
/*   Updated: 2023/03/01 12:31:38 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

// -lmlx -lXext -lX11

int	main(void)
{
	void	*val;
	void	*wind;

	val = mlx_init();
	wind = mlx_new_window(val, 800, 800, "Projetao");
	mlx_loop(val);
	return (0);
}


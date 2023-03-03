/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:17:42 by kfaustin          #+#    #+#             */
/*   Updated: 2023/03/03 13:50:22 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// lmlx uses to compile the internal sytem minilibx -lmlx -lXext -lX11
//# include "../minilibx-linux/mlx_init.h"
# include "../minilibx-linux/mlx.h"
# include "./get_next_line/get_next_line.h"
# include "./get_next_line/get_next_line_bonus.h"
# include "./libft/libft.h"

// Macros
# define WIN_WIDTH 800
# define WIN_HEIGHT 800
# define WALL "./sprites/wall.xpm"
# define FLOOR "./sprites/floor.xpm"

// Structs
typedef	struct s_window
{
	unsigned int	width;
	unsigned int	height;
	void			*ptr;
}	t_window;

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	// Window
	void	*wall;
	void	*floor;
	int		x;
	int		y;
	// Map
	int		x_dim;

}	t_data;

// Prototype


#endif

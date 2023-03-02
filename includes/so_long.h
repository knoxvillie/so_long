/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:17:42 by kfaustin          #+#    #+#             */
/*   Updated: 2023/03/02 14:53:16 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// lmlx uses to compile the internal sytem minilibx -lmlx -lXext -lX11
# include "../minilibx-linux/mlx.h"
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"

// Macros
# define WIN_WIDTH 259
# define WIN_HEIGHT 194
# define SPRITE "./includes/rr1.xpm"

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
	void	*sprite;
	int		x;
	int		y;
}	t_data;


#endif

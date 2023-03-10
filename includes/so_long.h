/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:43:49 by kfaustin          #+#    #+#             */
/*   Updated: 2023/03/10 13:06:10 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// lmlx uses to compile the internal system minilibx -lmlx -lXext -lX11
# include "../minilibx-linux/mlx.h"
# include "./libft/libft.h"

// ---- Macros
# define DIM 64
# define TITLE "WOLFGANG"
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
// -- Sprites
# define WALL "./sprites/wall.xpm"
# define FLOOR "./sprites/floor.xpm"
# define PLAYER "./sprites/player.xpm"
# define ENEMY "./sprites/enemy.xpm"
# define COLECT "./sprites/colect.xpm"

// Structs
typedef	struct s_window
{
	void	*ptr;
	int		x;
	int 	y;

}	t_window;

typedef struct	s_root
{
	void	*m_ptr;
	// sprites
	void	*wall;
	void	*floor;
	void	*enemy;
	void	*player;
	void	*colect;
	// ABS Position
	int		abs_x;
	int		abs_y;
	// Map
	char	**map;
	void	*w_ptr;
	int		x;
	int 	y;

}	t_root;

// Prototype

// - destroy.c
void	ft_destroy_mlx(t_root *root, int flag);
void	ft_free_2d_array(char **ptr);
void	ft_destroy_root(t_root *root, int flag);
int		ft_line_count(int fd);
// - event.c
int		ft_close_root(t_root *root);
int		ft_key_event(int keycode, t_root *root);
void	ft_check_rectangle_map(t_root *root);
// - general.c
void	ft_free_and_close(int fd, char *str);
// - map.c
char	**read_map(t_root *root, int fd);
void	ft_load_map(t_root *root);
void	ft_load_window(t_root *root, char *file);
// - so_long.c
// - validation.c
void	*ft_load_image(t_root *root, char *file);
void	ft_check_image(t_root *root);
void	ft_validation(t_root *root, char *file_name, const char *extension);
int		ft_check_fd(char *file);
void	ft_check_abs_xy(t_root *root, char *file);
void	ft_check_and_init_mlx(t_root *root);
void	ft_check_and_init_wind(t_root *root);
void	ft_check_map_name(char *file_name, const char *extension);
void	ft_check_valid_map(t_root *root);

#endif

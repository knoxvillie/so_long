/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:43:49 by kfaustin          #+#    #+#             */
/*   Updated: 2023/03/11 16:05:15 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// lmlx uses to compile the internal system minilibx -lmlx -lXext -lX11
# include "../minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

// ---- X11/X.h
# ifndef KeyPress
#  define KeyPress 2
# endif
# ifndef KeyPressMask
#  define KeyPressMask (1L<<0)
# endif

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
# define PLAYERR "./sprites/player.xpm"
# define PLAYERL "./sprites/playerl.xpm"
# define PLAYERB "./sprites/playerb.xpm"
# define ENEMY "./sprites/enemy.xpm"
# define COLLECT "./sprites/colect.xpm"
# define SCAPE "./sprites/exit.xpm"

// Structs
typedef struct	s_pos
{
	int		x;
	int		y;
}	t_pos;

typedef struct	s_root
{
	void	*m_ptr;
	// sprites
	void	*wall;
	void	*floor;
	void	*scape;
	void	*playerR;
	void	*playerL;
	void	*playerB;
	void	*collect;
	// ABS Position
	int		line;
	int		column;
	// Map
	char	**map;
	void	*w_ptr;
	int		x;
	int 	y;
	// Player
	int		player_x;
	int 	player_y;

	int 	moves;
	// Map elements
	int		start_point;
	int		colec_point;
	int 	exit_point;
	// Flood fill
	char	**mp;
	char	fill;
}	t_root;

// Prototype

// - destroy.c
void	ft_destroy_mlx(t_root *root, int flag);
void	ft_free_2d_array(char **ptr);
void	ft_destroy_root(t_root *root, int flag);
int		ft_line_count(int fd);
// - event.c
int		ft_close_root_event(t_root *root);
int		ft_key_event(int keycode, t_root *root);
void	ft_check_rectangle_map(t_root *root);
// - general.c
void	ft_free_and_close(int fd, char *str);
void	ft_count_map_elements(t_root *root);
void	ft_rotate_player_sprite(t_root *root, int to_x, int to_y);
char	**ft_dup_2d_array(t_root *root);
void	ft_flood_fill(t_root *root, int x, int y, char *elements);
void	ft_print_map(char **map, int x, int y);
void	ft_fill_wall_escape(char **str);
// - map.c
char	**read_map(t_root *root, int fd);
void	ft_load_map(t_root *root);
void	ft_load_window(t_root *root, char *file);
// - move.c
int		ft_check_valid_move(t_root *root, int to_x, int to_y);
int		ft_move_player(t_root *root, int to_x, int to_y);
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
void	ft_check_map_elements(t_root *root);
void	ft_check_valid_path(t_root *root);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:11:08 by kfaustin          #+#    #+#             */
/*   Updated: 2023/03/15 10:53:04 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

// lmlx uses to compile the internal system minilibx -lmlx -lXext -lX11
# include "../minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <time.h>

// ---- Macros
# define DIM 64
# define TITLE "so_long"
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
// -- Sprites
# define WALLONE "./sprites/wallone.xpm"
# define WALL "./sprites/wall.xpm"
# define FLOOR "./sprites/floor.xpm"
# define PLAYERR "./sprites/player.xpm"
# define PLAYERL "./sprites/playerl.xpm"
# define PLAYERB "./sprites/playerb.xpm"
# define ENEMY "./sprites/enemy.xpm"
# define ENEMYR "./sprites/enemyr.xpm"
# define ENEMYB "./sprites/enemyb.xpm"
# define COLLECT "./sprites/colect.xpm"
# define SCAPE "./sprites/exit.xpm"
# define SCAPE1 "./sprites/exit1.xpm"
# define SCAPE2 "./sprites/exit2.xpm"

// Structs
typedef struct s_root
{
	void	*m_ptr;
	void	*wall;
	void	*floor;
	void	*scape;
	void	*scape1;
	void	*scape2;
	void	*enemyidle;
	void	*enemy;
	void	*enemy_r;
	void	*enemy_b;
	void	*player_r;
	void	*player_l;
	void	*player_b;
	void	*collect;
	void	*img;
	int		line;
	int		column;
	char	**map;
	void	*w_ptr;
	int		x;
	int		y;
	int		player_x;
	int		player_y;
	int		moves;
	int		start_point;
	int		colec_point;
	int		exit_point;
	char	**mp;
	char	fill;
	int		e_x;
	int		e_y;
}	t_root;

// Prototype
// - destroy.c
void	ft_destroy_mlx(t_root *root, int flag);
void	ft_destroy_root(t_root *root, int flag);
void	ft_free_2d_array(char **ptr);
void	ft_kill_player(t_root *root);
// - enemy_bonus.c
void	ft_enemy_move(t_root *root);
// - event.c
int		ft_close_root_event(t_root *root);
int		ft_key_event(int keycode, t_root *root);
int		ft_event_frames(t_root *root);
// - general.c
void	ft_rotate_player_sprite(t_root *root, int to_x, int to_y);
void	ft_flood_fill(t_root *root, int x, int y, char *elements);
void	ft_count_map_elements(t_root *root);
void	ft_fill_wall_escape(char **str, int select);
// - general_a.c
void	ft_free_and_close(int fd, char *str);
char	**ft_dup_2d_array(t_root *root, int select);
void	ft_print_map(char **map, int x, int y);
void	ft_sleep(int value);
// - map.c
char	**read_map(t_root *root, int fd);
int		ft_line_count(int fd);
void	ft_load_map(t_root *root);
void	ft_load_window(t_root *root, char *file);
// - move.c
int		ft_check_valid_move(t_root *root, int to_x, int to_y);
int		ft_move_player(t_root *root, int to_x, int to_y);
// - so_long.c
// - validation.c
void	ft_validation(t_root *root, char *file_name, const char *extension);
void	*ft_load_image(t_root *root, char *file);
void	ft_check_image(t_root *root);
void	ft_check_and_init_mlx(t_root *root);
void	ft_check_and_init_wind(t_root *root);
// - validation_a.c
void	ft_check_valid_path(t_root *root, int select);
void	ft_check_map_elements(t_root *root);
void	ft_check_rectangle_map(t_root *root);
void	ft_check_valid_map(t_root *root);
void	ft_check_map_name(char *file_name, const char *extension);
// - validation_b.c
int		ft_check_fd(t_root *root, char *file);
void	ft_check_abs_xy(t_root *root, char *file);
void	ft_check_unknown(t_root *root, char pixel);
void	ft_player_coord(t_root *root, int i, int j);
void	ft_scape_coord(t_root *root, int i, int j);

#endif

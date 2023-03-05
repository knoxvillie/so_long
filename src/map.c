/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:08:35 by kfaustin          #+#    #+#             */
/*   Updated: 2023/03/05 19:14:20 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
 * @brief
 *
 * @param fd
 * @return int
 */

void	read_map(t_data *root, int fd)
{
	int		i;
	char	*line;
	char	**map;

	map = (char **)malloc(sizeof(char *) * (root->y_dim + 1));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map[1] = line;
	}
}

int	ft_line_count(int fd)
{
	int		size;
	char	*line;

	size = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		size++;
		free (line);
	}
	return (size);
}

void	load_window(t_data *root, char *map)
{
	int		fd;
	char	**map;

	fd = open(map, O_RDONLY);
	root->y_dim = ft_line_count(fd);
	if (root->y_dim < 2)
		;
	close (fd);

}

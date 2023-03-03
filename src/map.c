/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:08:35 by kfaustin          #+#    #+#             */
/*   Updated: 2023/03/03 14:38:42 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
 * @brief
 *
 * @param fd
 * @return int
 */

int	ft_line_count(int fd)
{
	int		size_x;
	char	*line;

	size_x = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free (line);
			break ;
		}
		size_x++;
		free (line);
	}
	return (size_x);
}

void	load_window(t_data *root, char *map)
{
	int		fd;
	char	**map;
	fd = open(map, O_RDONLY);
	root->x_dim = ft_line_count(fd);
	if (root->x_dim < 2)

}

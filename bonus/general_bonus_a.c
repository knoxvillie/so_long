/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_bonus_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:53:15 by kfaustin          #+#    #+#             */
/*   Updated: 2023/03/15 09:15:50 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_free_and_close(int fd, char *str)
{
	free (str);
	close (fd);
}

char	**ft_dup_2d_array(t_root *root, int select)
{
	int		j;
	int		i;
	char	**map_dup;
	char	*line;

	map_dup = (char **)malloc(sizeof(char *) * (root->column + 1));
	j = 0;
	while (j < root->column)
	{
		i = 0;
		line = (char *)malloc(sizeof(char) * (root->line + 1));
		while (i < root->line)
		{
			line[i] = root->map[j][i];
			i++;
		}
		line[i] = '\0';
		ft_fill_wall_escape(&line, select);
		map_dup[j++] = line;
	}
	map_dup[j] = NULL;
	return (map_dup);
}

void	ft_print_map(char **map, int x, int y)
{
	int	i;
	int	j;

	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			ft_printf("%c", map[j][i]);
			i++;
		}
		ft_printf("\n");
		j++;
	}
	ft_printf("\n");
}

void	ft_sleep(int value)
{
	int	i;

	i = 0;
	while (i < value)
		i++;
}

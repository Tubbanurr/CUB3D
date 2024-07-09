/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taksin <taksin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:17:43 by taksin            #+#    #+#             */
/*   Updated: 2024/07/09 17:45:36 by taksin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_map(t_game *game)
{
	char	*line;
	int		y;
	int		x;

	y = -1;
	x = -1;
	game->map.fd = open(game->map.map_path, O_RDONLY);
	game->map.map = (char **)malloc(sizeof(char *)
			* game->map.map_height);
	while (1)
	{
		line = get_next_line(game->map.fd);
		if (!line)
			break ;
		game->map.map[++y] = ft_stdup(line);

		while (line[++x] != '\0')
			game->map.map[y][x] = line[x];
		game->map.map[y][x] = '\0';
		free(line);
	}
	game->map.map[y] = NULL;
	if (y == 0)
		put_msg_exit("ERROR: Map is empty!\n");
	close(game->map.fd);
}

void	find_map_size(t_game *game)
{
	char	*line;

	game->map.fd = open(game->map.map_path, O_RDONLY);
	if (game->map.fd <= 0)
	{
		close(game->map.fd );
		put_msg_exit("ERROR: Map file could not be opened!\n");
	}
	line = get_next_line(game->map.fd );
	if (!line)
	{
		free(line);
		put_msg_exit("ERROR: get_next_line is faulty!\n");
	}
	while (1)
	{
		free(line);
		game->map.map_height++;
		line = get_next_line(game->map.fd );
		if (!line)
			break ;
	}
	if (!line)
		free(line);
	close(game->map.fd );
}


void	format_checker(int ac, char **av, t_game *game)
{
	int	i;

	if (ac != 2)
		put_msg_exit("ERROR: Argument count error! \n");
	i = 0;
	while (av[1][i])
		i++;
	if (av[1][i - 1] != 'b' && av[1][i - 2] != 'u' && av[1][i - 3] != 'c'
		&& av[1][i - 4] != '.')
		put_msg_exit("ERROR: File extension must be .cub ! \n");
	game->map.map_path = av[1];
	game->map.fd = open(game->map.map_path, O_RDONLY);
	if (game->map.fd <= 0)
	{
		close(game->map.fd);
		put_msg_exit("ERROR: Map file could not be opened!\n");
	}
}


int main(int ac, char **av)
{
	t_game game;
	format_checker(ac, av, &game);
	find_map_size(&game);
	create_map(&game);
	parsing_map(&game);


}

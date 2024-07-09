/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taksin <taksin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:03:35 by taksin            #+#    #+#             */
/*   Updated: 2024/07/09 16:39:16 by taksin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

#include "../libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53

typedef struct s_image
{
	void	*img;
	int		*addr;
	int		num;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_image;

typedef struct s_map
{
	char	**map;
	char	*map_path;
	int		map_height;
	int		real_height;
	char	*map_name;
	char	**tmp_map;
	int		fd;
	char	*floor;
	char	*ceiling;
	char	**real_map;
	char	*directions[4];
	char	*textures[4];
	int		playercount;
	int		posx;
	int		posy;
	char	pov;
	char	*color_path[2];
	char	*rgb_color[2];
	int		flags[6];
	int		infocount;
	int		endofinfo;
	int		f_color;
	int		c_color;
}			t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_image	*img;
	t_image	*north;
	t_image	*south;
	t_image	*west;
	t_image	*east;
	float	speed;
	float	rotspeed;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	camerax;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perp_wall_dist;
	double	wallx;
	double	raydirx;
	double	raydiry;
	double	step;
	double	texpos;
	int		color;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		line_h;
	int		floor;
	int		ceiling;
	int		draw_start;
	int		draw_end;
	int		tex_x;
	int		tex_y;
	int		tex_width;
	int		tex_height;
	int		exit_control;
	bool	w;
	bool	s;
	bool	a;
	bool	d;
	bool	left;
	bool	right;
	bool	shift;
}			t_game;




 #endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:05:36 by hregina           #+#    #+#             */
/*   Updated: 2022/06/25 08:39:40 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "../libft/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

# define PI 3.1415926535

typedef struct s_draw
{
	int		x;
	int		y;
	double	angle;
	double	angle_start;
	double	angle_end;
	double	angle_step;
	double	ray_x;
	double	ray_y;
	double	deltadistx;
	double	deltadisty;
	double	sidedistx;
	double	sidedisty;
	int		stepx;
	int		stepy;
	int		mapx;
	int		mapy;
	int		hit;
	int		side;
	double	perpwalldist;
	int		lineheight;
	double	wallx;
	int		drawstart;
	int		drawend;
	int		texx;
	double	step;
	double	texpos;
	int		texy;
	int		tn;
}	t_draw;

typedef struct s_tex
{
	void	*ptr;
	int		*data;
	int		width;
	int		height;
	int		bpp;
	int		size_l;
	int		endian;
}	t_tex;

typedef struct s_player
{
	double		x;
	double		y;
	double		angle;
	double		view;
	double		movespeed;
	double		rotspeed;
	int			mouse_x;
}	t_player;

typedef struct s_map
{
	int				height_f;
	int				width_f;
	int				f_color;
	int				c_color;
	char			*wall_texture_path[4];
	int				player_x;
	int				player_y;
	char			player_dir;
	char			**arr;
	t_tex			*tex;
}	t_map;

typedef struct s_data {
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_cub3d
{
	t_map			*map;
	t_player		*player;
	int				mlx_width;
	int				mlx_height;
	void			*mlx;
	void			*mlx_win;
	char			active_key[127];
	int				mouse;
	t_data			img;
}	t_cub3d;

//main
void	cub_error(char *error);
void	cub_hook(t_cub3d *cub);
int		cub_close(void);

//init
t_cub3d	*cub_init(char *map_file);

//parsing
t_map	*parsing_map(char *map_file);
t_list	*parsing_read_map(char *map_file, t_map *map);
void	parsing_read_line(int rd, char *line, t_map *map, t_list **head_map);
int		parsing_texture(char *s, t_map *map);
void	parsing_texture_main(char **split_line, t_map *map);
void	parsing_list_to_array(t_list *head, t_map *map);
void	parsing_check_map_surrounding(t_map *map);

//moving
void	update_move(t_cub3d	*cub);

//drawing
int		cub_draw(t_cub3d *cub);
void	cub_draw_wall(t_cub3d *cub);
void	cub_draw_wall2(t_cub3d *cub, t_draw *draw);
void	cub_draw_minimap(t_cub3d *cub);

#endif

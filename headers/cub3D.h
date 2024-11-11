/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:19:21 by shaintha          #+#    #+#             */
/*   Updated: 2024/11/11 13:10:06 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <string.h>
# include <fcntl.h>
# include <sys/time.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT	1080
# define PI	3.1415926535
# define NUM_OF_TEXTURES 4
# define IMAGE_WIDTH	64
# define IMAGE_HEIGHT	64

//Define keys
# define KEY_W		119
# define KEY_S		115
# define KEY_A		97
# define KEY_D		100
# define KEY_ESC	65307
# define KEY_LEFT	65361
# define KEY_RIGHT	65363

# define MOV_SPD 0.1
# define ROT_SPD 0.1

typedef struct s_image
{
	void	*ptr;
	int		x;
	int		y;
}					t_image;

typedef struct s_rays
{
	float	delta_dist_x;
	float	delta_dist_y;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	int		side;
	float	init_step_x;
	float	init_step_y;
	float	ray_dir_x;
	float	ray_dir_y;
	float	wall_height;
}					t_rays;

typedef struct s_player
{
	float	pos_x;
	float	pos_y;
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y;
}					t_player;

typedef struct s_cube
{
	void	*mlx_ptr;
	void	*window_ptr;
	char	*map_str;
	char	**map;
	char	*n_path;
	char	*e_path;
	char	*s_path;
	char	*w_path;
	char	*f_color;
	char	*c_color;
	t_image	wall_north;
	t_image	wall_east;
	t_image	wall_south;
	t_image	wall_west;
	int		floor_color;
	int		ceiling_color;
	int		map_pos;
	int		error_code;
	t_player	player;
}			t_cube;


//----------PLS--DO--NOT--CHANGE--FUNCTIONS--BELOW-----------//

//initialize.c
void	initialize_cube(t_cube *cube);
void	free_cube(t_cube *cube);

//utils.c
bool    is_format_valid(char *file, char *format);
bool	is_color_valid(char *color_str);
int		get_color(char *color_str);
void	put_error(char *error_message);

//map.c
int		parse_map(t_cube *cube, char *map_name);
char	*get_map_content(char *file_name);
char	*read_map(int fd, char *line, char *temp, int bytes_read);
size_t	get_map_startline(char *map_str, size_t i, size_t j);
bool	has_map_empty_line(char *str, char first_char_of_file);

//map_information.c
bool    is_information_valid(t_cube *cube, char *map_str, size_t end);
int		parse_information(t_cube *cube, char *map_str, size_t end, size_t i);
char	*get_id_content(t_cube *cube, char *id_str, char *id_content, size_t *i);

//map_layout.c
bool	is_layout_valid(char **map, size_t x, size_t y, bool found);
bool	is_in_border(char **map, size_t x, size_t y);
bool	is_map_element(char e);

//image.c
t_image	get_image(t_cube *cube, char *image_path);
int		get_images(t_cube *cube);
void	free_images(t_cube *cube);

//----------PLS--DO--NOT--CHANGE--FUNCTIONS--ABOVE-----------//

//cube.c
int		setup_cube(t_cube *cube);
int		run_cube(t_cube *cube);
int		key_pressed(int syskey, t_cube *cube);
int		close_cube(t_cube *cube);

//player.c
void	get_player_info(t_player *player, char **map);
void	get_player_direction_1(t_player *player, char dir_char);
void	get_player_direction_2(t_player *player, char dir_char);
void	move_pov(t_cube *cube, int syskey);
void	rotate_pov(t_cube *cube, int syskey);

//raycaster.c
void	calc_rays(t_cube *cube, t_player *player, t_rays *rays);
void	calc_distances(t_cube *cube, t_player *player, t_rays *rays);
void	check_next_wall(t_cube *cube, t_player *player, t_rays *rays);
void	calc_wall_height(t_cube *cube, t_player *player, t_rays * rays);
bool	is_wall(t_cube *cube, float x, float y);

#endif
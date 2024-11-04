/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:19:21 by shaintha          #+#    #+#             */
/*   Updated: 2024/10/28 11:57:54 by shaintha         ###   ########.fr       */
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

# define PI	3.1415926535
# define IMAGE_WIDTH	64
# define IMAGE_HEIGHT	64
# define MOV_SPD 0.1
# define ROT_SPD 0.1

//Define keys
# define KEY_W		119
# define KEY_S		115
# define KEY_A		97
# define KEY_D		100
# define KEY_ESC	65307
# define KEY_LEFT	65361
# define KEY_RIGHT	65363

typedef struct s_image
{
	void	*ptr;
	int		x;
	int		y;
}					t_image;

typedef struct s_player
{
	float	fov;
	float	pos_x;
	float	pos_y;
	float	dir_x;
	float	dir_y;
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


void	initialize_cube(t_cube *cube);
void	initialize_images(t_cube *cube);
void	free_cube(t_cube *cube);

//map.c
bool	is_in_border(char **map, size_t x, size_t y);
bool	is_layout_valid(char **map, size_t x, size_t y, bool found);
int		parse_map(t_cube *cube, char *map_name);
int		identifier_check(t_cube *cube, char *map_str, size_t end);
char	*get_map_str(char *map_name);
char	*read_map(int fd, char *line, char *temp, int bytes_read);
int		get_identifier(t_cube *cube, char *map_str, size_t end);
bool	is_map_element(char e);
bool	is_in_border(char **map, size_t x, size_t y);
size_t	get_map_startline(char *map_str);
bool	has_map_empty_line(char *map_str);


//utils.c
bool    is_format_valid(char *file, char *format);
bool    is_information_valid(t_cube *cube, char *map_str, size_t end);

void	put_error(char *error_message);
int		ft_strncmp_pos(const char *str1, const char *str2, size_t n, size_t *pos);
int		skip_spaces(char *str, size_t *pos);
int		skip_nl(char *str, size_t *pos);
int		skip_spaces_nl(char *str, size_t *pos);
char	*ft_strdup_nl(const char *src, size_t *pos);
char	*ft_strdup_nl2(const char *src);
char	*get_id_content(t_cube *cube, char *id_str, char *id_content, size_t *i);
bool	are_identifiers_valid(t_cube *cube, char *map_str, size_t end);
int		parse_information(t_cube *cube, char *map_str, size_t end, size_t i);


bool	is_color_valid(char *color_str);
int		get_color(char *color_str);
int		rgb_to_int(int red, int green, int blue);
t_image	get_image(t_cube *cube, char *image_path);
int		get_images(t_cube *cube);

//cube.c
int		run_cube(t_cube *cube);
int	setup_cube(t_cube *cube);
int	close_cube(t_cube *cube);
void	print_cube(t_cube *cube);
void	free_images(t_cube *cube);
void	free_mlx(t_cube *cube);

int		key_pressed(int syskey, t_cube *cube);
bool	is_wall(t_cube *cube, float x, float y);
void	get_player_info(t_player *player, char **map);
void	get_player_direction(t_player *player, char dir_char);
void	move_pov(t_cube *cube, int syskey);

#endif
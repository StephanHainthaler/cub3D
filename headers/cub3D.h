/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:19:21 by shaintha          #+#    #+#             */
/*   Updated: 2024/10/10 14:47:04 by shaintha         ###   ########.fr       */
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
	void			*ptr;
	unsigned int	x;
	unsigned int	y;
}					t_image;

typedef struct s_cube
{
	void	*mlx_ptr;
	void	*window_ptr;
	char	**map;
	char	*n_path;
	char	*e_path;
	char	*s_path;
	char	*w_path;
	char	*f_color;
	char	*c_color;
	t_image	*wall_north;
	t_image	*wall_east;
	t_image	*wall_south;
	t_image	*wall_west;
	int		map_pos;
}			t_cube;


void	initialize_cube(t_cube *cube);
void	free_cube(t_cube *cube);

//map.c
int		parse_map(t_cube *cube, char *map_name);
int		map_check_julian(t_cube *cube, char *map_str);
char	*get_map_str(char *map_name);
char	*read_map(int fd, char *line, char *temp, int bytes_read);
int		get_identifier(t_cube *cube, char *map_str);
bool	is_map_valid(char **map, size_t x, size_t y, bool found);
bool	is_in_border(char **map, size_t x, size_t y);
int	get_map_startline(char *map_str);
bool	has_empty_line(char *map_str);


//utils.c
bool    is_format_valid(char *file, char *format);
void	put_error(char *error_message);
int		ft_strncmp_pos(const char *str1, const char *str2, size_t n, int *pos);
int		skip_spaces_nl(char *str, int *pos);
int		skip_spaces_nl(char *str, int *pos);
char	*ft_strdup_nl(const char *src);

#endif
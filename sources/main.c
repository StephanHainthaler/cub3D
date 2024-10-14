/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:18:58 by shaintha          #+#    #+#             */
/*   Updated: 2024/10/14 12:59:09 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

int main(int argc, char *argv[])
{
	t_cube	cube;
	
	if (argc != 2)
		return (printf("Wrong number of arguments\n"), 1);
	if (is_format_valid(argv[1], ".cub") == false)
		return (printf("Wrong format\n"), 1);
	initialize_cube(&cube);
	//MAP PARSING
	if (parse_map(&cube, argv[1]) == 1)
		return (1);
    printf("North Wall Path: %s\n", cube.n_path);
    printf("East Wall Path: %s\n", cube.e_path);
    printf("South Wall Path: %s\n", cube.s_path);
    printf("West Wall Path: %s\n", cube.w_path);
    printf("Floor Color Code: %s\n", cube.f_color);
    printf("Ceiling Color Code: %s\n", cube.c_color);
    printf("Map-Layout:\n");
    ft_putstrarr_fd(cube.map, 1);
	return (0);
}

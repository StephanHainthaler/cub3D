/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:18:58 by shaintha          #+#    #+#             */
/*   Updated: 2024/11/19 09:55:35 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

int	main(int argc, char *argv[])
{
	t_cube	cube;

	if (argc != 2)
		return (put_error("Wrong number of arguments"), 1);
	if (is_format_valid(argv[1], ".cub") == false)
		return (put_error("Wrong format"), 1);
	initialize_cube(&cube);
	if (parse_map(&cube, argv[1]) == 1)
		return (1);
	if (run_cube(&cube) == 1)
		return (1);
	free_cube(&cube);
	return (0);
}

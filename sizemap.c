/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:09:04 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/10/09 02:24:30 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_mat(char **mat)
{
	int	y;
	int	x;

	y = 0;
	while (mat[y])
	{
		x = 0;
		while (mat[y][x])
		{
			write(1, &mat[y][x], 1);
			x++;
		}
		y++;
		write(1, "\n", 1);
	}
}


void	ft_check_input( int ac, char *av)
{
	int	len;

	if (ac != 2)
		exit(write(2, "Error: Invalid input\n", 21));
	len = ft_strlen(av);
	if (!(av[len - 1] == 'b' && av[len - 2] == 'u' && av[len - 3]
			== 'c' && av[len - 4] == '.'))
		exit(write(2, "Error: Map isnt in .cub format\n", 24));
}
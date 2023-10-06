/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:00:25 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/10/06 14:09:18 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include "mlx/mlx.h"
//# include "minilibx-linux/mlx.h"
//# include "libft/libft.h"
# include "getnextline/get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <time.h>
# include <sys/time.h>

typedef struct  s_maps
{
    char **readmap;
    char **map;
    int x;
    int y;
};


#endif
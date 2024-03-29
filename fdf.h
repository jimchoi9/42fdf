/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:18:23 by jimchoi           #+#    #+#             */
/*   Updated: 2024/03/27 19:35:28 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
# define FDF_H

#include <unistd.h>
#include "./minilibx_mms_20210621/mlx.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include <stdio.h>

//이미지의 정보를 나타내는 변수를 저장한 구조체
typedef struct s_data
{
	void 	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

typedef struct s_point
{
	int x;
	int y;
	int z;
	unsigned int color;
}		t_point;

typedef struct s_map
{
	int width;
	int height;
	int max_z;
	t_point **points;
}		t_map;

typedef struct s_xy{
	int	x1;
    int	y1;
	int	x2;
	int	y2;
} t_xy;

typedef struct s_linedata{
	int	w;
    int	h;
	int	add_x;
	int	add_y;
} t_linedata;

t_map	*parsing(char *argv[]);
void bresenham(t_xy xy, int x2, int y2, t_data image);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	b2(t_xy xy, int x2, int y2, t_data image);
#endif
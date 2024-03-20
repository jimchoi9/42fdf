/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:18:23 by jimchoi           #+#    #+#             */
/*   Updated: 2024/03/20 16:55:54 by jimchoi          ###   ########.fr       */
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


void	parsing(char *argv[]);
void bresenham(int x1, int y1, int x2, int y2, t_data image, int color);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
#endif
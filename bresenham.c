/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:20:53 by jimchoi           #+#    #+#             */
/*   Updated: 2024/03/27 20:25:53 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

int	abs(int num)
{
	if (num < 0)
		return (-num);
    else
		return (num);
}

void	drowb1(t_xy xy, t_linedata line, t_data image)
{
	int	count;
	int	i;
	
	count = 0;
	i = 0;
	while (i < line.w)
		{
			//x를 1증가 시키고 dy만큼 count 증가
			xy.x1 += line.add_x;
			//x의 증가만큼 count 증가
			count += line.h;

			//증가하는 y값보다 크다면 
			if(count >= line.w)
			{
				//y 를 1 증가시키고 count를 초기화
				xy.y1 += line.add_y;
                count -= line.w;
			}
			// printf("x = %d, y = %d\n", x, y);
			if (xy.x1 < 1920 && xy.y1 < 1080 && xy.x1 >= 0 && xy.y1 >= 0)
				my_mlx_pixel_put(&image,xy.x1 , xy.y1 , 0xffffff);
			i++;
		}
}
void	drowb2(t_xy xy, t_linedata line, t_data image)
{
	int	count;
	int	i;
	
	count = 0;
	i = 0;
		while(i < line.h)
		{
			//x를 1증가 시키고 dy만큼 count 증가
			xy.y1 += line.add_y;
			//x의 증가만큼 count 증가
			count += line.w;

			//증가하는 y값보다 크다면 
			if(count >= line.h)
			{
				//y 를 1 증가시키고 count를 초기화
				xy.x1 += line.add_x;
                count -= line.h;
			}
			// printf("x = %d, y = %d\n", x, y);
			if (xy.x1 < 1920 && xy.y1 < 1080 && xy.x1 >= 0 && xy.y1 >= 0)
				my_mlx_pixel_put(&image,xy.x1 , xy.y1 , 0xffffff);
			i++;
		}
}

void bresenham(t_xy xy, int x2, int y2, t_data image)
{
	t_linedata	line;
	int addx, addy;
	int count = 0;

line.add_x = 1;
line.add_y = 1;
	int dx = x2 - xy.x1;
	int dy = y2 - xy.y1;
	line.w = abs(x2 - xy.x1);
	line.h = abs(y2 - xy.y1);
	if (x2 - xy.x1 < 0)
		line.add_x = -1;
	if (y2 - xy.y1 < 0)
		line.add_y = -1;

	if (line.w >= line.h)
    {
		drowb1(xy, line, image);
    }
	//dx < dy 일 경우 (기울기 > 1) x의 조건이 만족하면 y를 1 증가시킨다
    else
    {
		drowb2(xy, line, image);
		
    }
}

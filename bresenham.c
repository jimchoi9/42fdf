/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:20:53 by jimchoi           #+#    #+#             */
/*   Updated: 2024/03/21 16:53:06 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

	// double x = 0;
	// double y = 0;
	// double theta = 3.14 / 4.0;
	// for (int i = 0 ; i <= 200 ; i++)
	// {
	// 	for (int j = 0 ; j <= 200 ; j++)
	// 	{
	// 		if (i % 20 == 0 || j % 20 == 0)
	// 		{
	// 		my_mlx_pixel_put(&image, x + j + 100, y + i + 100,  0x00FF00 * i);
	// 		my_mlx_pixel_put(&image, ((x + j)* cos(theta) - (y+i) * sin(theta))+ 200, ((x+j)*sin(theta)+(y+i)*cos(theta)),  0x00FF00* i);
	// 		}
	// 	}
	// }

void bresenham(int x1, int y1, int x2, int y2, t_data image, int color)
{
	int addx, addy;
	int count = 0;

	int dx = x2 - x1;
	int dy = y2 - y1;

	//음수방향
	if (dx < 0)
    {
        dx = -dx;
        addx = -1;
    }
    else
        addx = 1;
	if (dy < 0)
	{
		dy = -dy;
        addy = -1;
	}
	else
		addy = 1;

	int x = x1;
	int y = y1;
	// printf("x: %d, y: %d\n", x, y);
	if (dx >= dy)
    {
		printf("xxxx");
		for(int i = 0; i < dx; i++)
		{
			//x를 1증가 시키고 dy만큼 count 증가
			x += addx;
			//x의 증가만큼 count 증가
			count += dy;

			//증가하는 y값보다 크다면 
			if(count >= dx)
			{
				//y 를 1 증가시키고 count를 초기화
				y += addy;
                count -= dx;
			}
			// printf("x = %d, y = %d\n", x, y);
			my_mlx_pixel_put(&image,x + 400, y + 400, color);

		}
    }
	//dx < dy 일 경우 (기울기 > 1) x의 조건이 만족하면 y를 1 증가시킨다
    else
    {
		printf("yyyy");
        for(int i=0; i<dy; i++)
		{
			
			//y를 1증가 시키고 dx만큼 count 증가
            y += addy;
            //y의 증가만큼 count 증가
            count += dx;

            //증가하는 x값보다 크다면 
            if(count >= dy)
            {
                //x 를 1 증가시키고 count를 초기화
                x += addx;
                count -= dy;
            }
            // printf("x = %d, y = %d\n", x,y);
			my_mlx_pixel_put(&image,x + 200, y + 200, color);
		}
    }
}
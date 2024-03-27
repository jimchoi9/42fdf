/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:37:22 by jimchoi           #+#    #+#             */
/*   Updated: 2024/03/27 20:51:53 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	make_center(t_map *map, int w, int h)
{
	int i = 0; 
	int j = 0;

	while (i < map->height)
    {
        while (j < map->width)
        {
			map->points[i][j].x += w;
			map->points[i][j].y += h;
            j++;
        }
        i++;
        j = 0;
    }
}

void	convert_isometric(t_map *map, int gap)
{
	int		i;
    int		j;
	int		dx;
	int		dy;
	t_xy	xy;

	i = 0;
	gap = 1920 / 3 / map->width;
	double theta = 3.14/6;
    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
				dx = map->points[i][j].x * gap;
				dy = map->points[i][j].y * gap ;
				xy.x1 = (dx- dy)*cos(theta);
				xy.y1 = (dx + dy)*sin(theta) - map->points[i][j].z * 2;
				map->points[i][j].x = xy.x1;
				map->points[i][j].y = xy.y1;
            j++;
        }
        i++;
    }
		make_center(map, 1920/2 - map->points[map->height/2][map->width/2].x \
		,1080/2 - map->points[map->height/2][map->width/2].y );
}

void draw_map(t_data image, t_map *map, unsigned int color)
{
	int		i;
    int		j;
	t_xy	xy;

	i = 0;
	while (i < map->height )
	{
		j = 0;
		while (j < map->width )
		{
			xy.x1 = map->points[i][j].x;
			xy.y1 = map->points[i][j].y ;
			if (j < map->width - 1)
				bresenham(xy ,map->points[i][j + 1].x, map->points[i][j + 1].y, image);
				// b2(xy, map->points[i][j + 1].x,  map->points[i][j + 1].y ,image);
			if (i < map->height - 1)
				bresenham(xy ,map->points[i + 1][j].x, map->points[i + 1][j].y, image);
				// b2(xy, map->points[i + 1][j].x,  map->points[i + 1][j].y ,image);
			j++;
		}
		i++;
	}
}

int key_press(int keycode)
{
	if (keycode == 53)
        exit(0);
	return (0);
}

int exit_key()
{
	exit(0);
}


int main(int argc, char *argv[])
{
	char	*str;
	void	*mlx_ptr;
	void	*win_ptr;
	t_map *map;
	t_data	image;

	if (argc != 2)
		printf("argc = %d\n", argc);
	str = ft_strrchr(argv[1], '.');
	if (ft_strncmp(str, ".fdf", 3) != 0)
		printf("str=%s.\nfdf=%s.\n에러메세지 출력 후 종료", str, ".fdf");
	map = parsing(argv);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "Hellow World!");
	image.img = mlx_new_image(mlx_ptr, 1920, 1080); // 이미지 객체 생성
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, \
	&image.line_length, &image.endian); // 이미지 주소 할당
	mlx_hook(win_ptr, 2, 0, &key_press, 0);
	mlx_hook(win_ptr, 17, 0, &exit_key, 0);
	convert_isometric(map, 10);
	draw_map(image, map, 0xff0000); 
	mlx_put_image_to_window(mlx_ptr, win_ptr, image.img, 5, 5);
	mlx_loop(mlx_ptr);
	
	return (0);
}
void check_leaks(void)
{ system("leaks test1"); } 

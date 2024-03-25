#include "fdf.h"
//export DYLD_LIBRARY_PATH=/Users/jimchoi/Desktop/sub/42fdf/minilibx_mms_20210621


// -출력 위치조정
// -맵 크기조정?

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void	convert_isometric(t_map *map, int gap)
{
	int i = 0;
    int j = 0;
	int dx;
	int dy;

	int center = 500 - (map->height / 2 * gap);
	if (map->width > map->height)
		center = 500 - (map->width / 2*gap);
	double a = 30 * 3.141592 / 180;

	// gap = () ;
	// gap = 10;

    while (i < map->height)
    {
        while (j < map->width)
        {
				dx = map->points[i][j].x * gap;
				dy = map->points[i][j].y * gap ;
				dx = (dx - dy)*cos(a);
				dy = (map->points[i][j].x * gap + dy)*sin(a) - map->points[i][j].z ;
				// map->points[i][j].x = dx ;
				// map->points[i][j].y = dy ;
				map->points[i][j].x = dx + center;
				map->points[i][j].y = dy + center;
            j++;
        }
        i++;
        j = 0;
    }

}



void draw_map(t_data image, t_map *map, unsigned int color)
{
	int i = 0;
    int j = 0;
	int dx;
	int dy;

	i = 0;
	j = 0;
    while (i < map->height)
    {
        while (j < map->width)
        {
			dx = map->points[i][j].x;
			dy = map->points[i][j].y ;
				if (j < map->width - 1)
					bresenham(dx, dy, map->points[i][j + 1].x,map->points[i][j + 1].y, image);
				if (i < map->height -1)
					bresenham(dx, dy, map->points[i + 1][j].x, map->points[i + 1][j].y, image);
            j++;
        }
        i++;
        j = 0;
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
	int		fd;
	char	*str;
	t_map *map;

	if (argc != 2)
		printf("ㅇㅔ러메세지 출력 후 종료");
	str = ft_strchr(argv[1], '.');
	if (ft_strncmp(str, ".fdf", 5) != 0)
		printf("에러메세지 출력 후 종료");


	void	*mlx_ptr;
	void	*win_ptr;
	t_data	image;


	map = parsing(argv);

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "Hellow World!");
	image.img = mlx_new_image(mlx_ptr, 1000, 1000); // 이미지 객체 생성
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian); // 이미지 주소 할당
	mlx_hook(win_ptr, 2, 0, &key_press, 0);
	mlx_hook(win_ptr, 17, 0, &exit_key, 0);


	// convert_isometric(map, 100/map->width);
	convert_isometric(map, 10);
	draw_map(image, map, 0xff0000); 

	mlx_put_image_to_window(mlx_ptr, win_ptr, image.img, 5, 5);
	mlx_loop(mlx_ptr);
	
	return (0);
}
void check_leaks(void)
{ system("leaks test1"); } 

#include "fdf.h"
//export DYLD_LIBRARY_PATH=/Users/jimchoi/Desktop/sub/42fdf/minilibx_mms_20210621
//원하는 좌표에 해당하는 주소에 color값을 넣는 함수
void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void print_pixel(t_data image, double t, unsigned int color)
{
	double theta = 3.14/t;
	int m = 250;
	int x1= 0;
	int y1= 0;
	int x2= 200;
	int y2= 200;
	
	bresenham(x1, y1, x1, y2, image, 0xff0000);
	bresenham(x1, y1, x2, y1, image, 0xff0000);
	bresenham(x2, y1, x2, y2, image, 0xff0000);
	bresenham(x1, y2, x2, y2, image, 0xff0000);



	bresenham(x1, y1, (x1 * cos(theta) - y2 * sin(theta)), (x1 * sin(theta) + y2 * cos(theta)) , image, color);
	bresenham(x1, y1, (x2 * cos(theta) - y1 * sin(theta)), (x2 * sin(theta) + y1 * cos(theta)), image, color);
	bresenham((x2 * cos(theta) - y2 * sin(theta)),(x2 * sin(theta) + y2 * cos(theta)), (x2 * cos(theta) - y1 * sin(theta)), (x2 * sin(theta) + y1 * cos(theta)), image,color);
	bresenham((x1 * cos(theta) - y2 * sin(theta)),(x1 * sin(theta) + y2 * cos(theta)), (x2 * cos(theta) - y2 * sin(theta)),(x2 * sin(theta) + y2 * cos(theta)), image, color);


}





void draw_map(t_data image, t_map *map, unsigned int color)
{
	int i = 0;
    int j = 0;
	int dx;
	int dy;
	int a = 60;
    while (i < map->height)
    {
        while (j < map->width)
        {
				dx = map->points[i][j].x * 20;
				dy = map->points[i][j].y * 20;
				dx = (dx - dy)*cos(a);
				dy = (map->points[i][j].x * 20 + dy)*sin(a) - map->points[i][j].z ;
				map->points[i][j].x = dx;
				map->points[i][j].y = dy;
            j++;
        }
        i++;
        j = 0;
    }
	i = 0;
	j = 0;
    while (i < map->height)
    {
        while (j < map->width)
        {
			dx = map->points[i][j].x;
			dy = map->points[i][j].y ;
				if (j < map->width - 1)
					bresenham(dx, dy, map->points[i][j + 1].x,map->points[i][j + 1].y, image, 0xffff00);
				if (i < map->height -1)
					bresenham(dx, dy, map->points[i + 1][j].x, map->points[i + 1][j].y, image, 0xffff00);
            j++;
        }
        i++;
        j = 0;
    }
}

int main(int argc, char *argv[])
{
	int	fd;
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


	draw_map(image, map, 0xff0000); 

	mlx_put_image_to_window(mlx_ptr, win_ptr, image.img, 5, 5);
	mlx_loop(mlx_ptr);
	return (0);
}
void check_leaks(void)
{ system("leaks test1"); } 

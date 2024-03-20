#include "fdf.h"
//export DYLD_LIBRARY_PATH=/Users/jimchoi/Desktop/sub/42fdf/minilibx_mms_20210621
//원하는 좌표에 해당하는 주소에 color값을 넣는 함수
void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void print_pixel(t_data image)
{
	double theta = 3.14/3.0;
	int m = 250;
	int x1= 0;
	int y1= 0;
	int x2= 200;
	int y2= 100;

	// x1 += m;
	// y1 += m;
	// x2 += m;
	// y2 += m;
	
	bresenham(x1, y1, x1, y2, image, 0xff0000);
	bresenham(x1, y1, x2, y1, image, 0xff0000);
	bresenham(x2, y1, x2, y2, image, 0xff0000);
	bresenham(x1, y2, x2, y2, image, 0xff0000);



	bresenham(x1, y1, (x1 * cos(theta) - y2 * sin(theta)), (x1 * sin(theta) + y2 * cos(theta)) , image, 0xff00f0);
	bresenham(x1, y1, (x2 * cos(theta) - y1 * sin(theta)), (x2 * sin(theta) + y1 * cos(theta)), image, 0xff00f0);
	bresenham((x2 * cos(theta) - y2 * sin(theta)),(x2 * sin(theta) + y2 * cos(theta)), (x2 * cos(theta) - y1 * sin(theta)), (x2 * sin(theta) + y1 * cos(theta)), image, 0xff00f0);
	bresenham((x1 * cos(theta) - y2 * sin(theta)),(x1 * sin(theta) + y2 * cos(theta)), (x2 * cos(theta) - y2 * sin(theta)),(x2 * sin(theta) + y2 * cos(theta)), image, 0xff00f0);

}

int main(int argc, char *argv[])
{
	int	fd;
	char	*str;

	if (argc != 2)
		printf("ㅇㅔ러메세지 출력 후 종료");
	str = ft_strchr(argv[1], '.');
	if (ft_strncmp(str, ".fdf", 5) != 0)
		printf("에러메세지 출력 후 종료");


	void	*mlx_ptr;
	void	*win_ptr;
	t_data	image;


	parsing(argv);

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 555, 555, "Hellow World!");
	image.img = mlx_new_image(mlx_ptr, 555, 555); // 이미지 객체 생성
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian); // 이미지 주소 할당
	// double theta = 3.14 / 3.0;
	// int x1 = 0;
	// int y1 = 0;
	// int x2 = 100;
	// int y2 = 400;
	// bresenham(0 , 0, x, 0, image);
	// bresenham(250 , 0, 250, 500, image, 0x00FF00);
	// bresenham(0,250, 500,250, image, 0x00FF00);
	print_pixel(image);
	// bresenham(250,250, ,  image);
	// bresenham(250 , 250, x, y, image);
	// bresenham(250 + x1, 250 + y1, 250 + x2, ((x2)*sin(theta)+(y2)*cos(theta)), image,  0xff0000);
	// x2 = 200;
	// bresenham(250 + x1, 250 + y1, 250 + x2, ((x2)*sin(theta)+(y2)*cos(theta)), image, -677);
	// bresenham(250 , 250, 250 - x2, ((x2)*sin(theta)+(y2)*cos(theta)), image);
	// for(int i = 0; i <=100; i++)
	// {
	// 	if (i % 10 == 0)
	// 	{
	// 		// my_mlx_pixel_put(&image, 250 + x1 +i, 250 + y1 , 0xff0000);
	// 		my_mlx_pixel_put(&image, 250 +x1 +i,i+ ((x1)*sin(theta)+(y2)*cos(theta)), 0xff0000);
	// 		my_mlx_pixel_put(&image, 250 +x1 +i,i+ ((x1)*sin(theta)+(y2)*cos(theta)) + 1, 0xff0000);
	// 	}
	// }
	// bresenham(250 , 250, (x* cos(theta) - (y) * sin(theta)), ((x)*sin(theta)+(y)*cos(theta)), image);
	// bresenham(100, 100, 200, 50, image);
	// double x = 0;
	// double y = 0;
	// // for (int i = 0 ; i <= 200 ; i++)
	// {
		
	// 	for (int j = 0 ; j <= 200 ; j++)
	// 	{
	// 		// if (i % 20 == 0 || j % 20 == 0)
	// 		{
	// 		my_mlx_pixel_put(&image, x + j, y,  0x00FF00 );
	// 		my_mlx_pixel_put(&image, ((x + j)* cos(theta) - (y) * sin(theta)), ((x+j)*sin(theta)+(y)*cos(theta)),  0x00FF00);
	// 		}
	// 	}
	// }

	mlx_put_image_to_window(mlx_ptr, win_ptr, image.img, 5, 5);
	mlx_loop(mlx_ptr);
	return (0);
}
void check_leaks(void)
{ system("leaks test1"); } 

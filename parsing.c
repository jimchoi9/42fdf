#include <stdio.h>
#include "./get_next_line/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void parsing(int argc, char *argv[])
{

}

int main()
{

	int fd = open("./42.fdf", O_RDONLY);
	printf("%d",fd);
	// while((ret = get_next_line(fd)) > 0)
	// {
		// printf("return : %d\n",ret);
		printf("line : %s\n",get_next_line(fd));
		printf("line : %s\n",get_next_line(fd));
		printf("line : %s\n",get_next_line(fd));
		printf("line : %s\n",get_next_line(fd));
	// }
	return (0);
}
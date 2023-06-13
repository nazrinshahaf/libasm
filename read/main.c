#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

extern ssize_t ft_read(int fildes, void *buf, size_t nbyte);

int main()
{
	char buff[1024];
	char buff2[1024];
	int fd = open("test.txt", 0);
	int fd2 = open("test.txt", 0);

	ft_read(fd, buff, 100);
	read(fd2, buff2, 100);
	printf("real = %s\n", buff);
	printf("mine = %s\n", buff2);
	return 0;
}

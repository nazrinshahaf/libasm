#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

extern ssize_t ft_read(int fildes, void *buf, size_t nbyte);

int main()
{
	errno = 0;
	{
		int fd = open("normal.txt", 0);
		int fd2 = open("normal.txt", 0);
	
		char buff[1024] = {0};
		char buff2[1024] = {0};
	
		read(fd, buff, 100);
		printf("real = [%s]\nreal errno = %d\n", buff, errno);
		errno = 0;
	
		printf("--------------------------------------\n");
	
		ft_read(fd2, buff2, 100);
		printf("mine = [%s]\nmy errno = %d\n", buff2, errno);
		close(fd);
		close(fd2);
	}
	
	errno = 0;
	printf("\n==========================================\n\n");
	{
		int fd = open("normal.txt", 0);
		int fd2 = open("normal.txt", 0);
	
		char buff[1024] = {0};
		char buff2[1024] = {0};
	
		read(-100, buff, 100);
		printf("real = [%s]\nreal errno = %d\n", buff, errno);
		errno = 0;
	
		printf("--------------------------------------\n");
	
		ft_read(-100, buff2, 100);
		printf("mine = [%s]\nmy errno = %d\n", buff2, errno);
		close(fd);
		close(fd2);
	}
	errno = 0;
	printf("\n==========================================\n\n");
	{
		int fd = open("no_access.txt", 0);
		int fd2 = open("no_access.txt", 0);
	
		char buff[1024] = {0};
		char buff2[1024] = {0};
	
		read(fd, buff, 100);
		printf("real = [%s]\nreal errno = %d\n", buff, errno);
		errno = 0;
	
		printf("--------------------------------------\n");
	
		ft_read(fd2, buff2, 100);
		printf("mine = [%s]\nmy errno = %d\n", buff2, errno);
		close(fd);
		close(fd2);
	}
	return 0;
}

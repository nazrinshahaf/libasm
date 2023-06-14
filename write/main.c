#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

extern ssize_t ft_write(int filedes, const void *buf, size_t nbyte);

int main()
{
	char str[] = "some stuff to write";
	printf(" | %zd | my write\n", ft_write(1, str, strlen(str)));
	printf("errno = %d\n", errno);

	errno = 0;
	printf(" | %zd | real write\n", write(1, str, strlen(str)));
	printf("errno = %d\n", errno);

	printf("\n==============================================\n\n");


	//invalid file descriptor
	errno = 0;
	printf(" | %zd | real write\n", write(100, str, strlen(str)));
	printf("errno = %d\n", errno);

	errno = 0;
	printf(" | %zd | my write\n", ft_write(100, str, strlen(str)));
	printf("errno = %d\n", errno);

	return 0;
}

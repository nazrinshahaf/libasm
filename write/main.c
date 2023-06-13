#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

extern ssize_t ft_write(int filedes, const void *buf, size_t nbyte);

int main()
{
	char str[] = "lasdbnajsd\n";
	printf(" | %zd\n", ft_write(1, str, strlen(str)));
	printf(" | %zd\n", write(1, str, strlen(str)));

	printf(" | %zd\n", ft_write(1, str, 2));
	printf(" | %zd\n", write(1, str, 2));
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

extern char *ft_strdup(const char *s1);

int main()
{
	errno = 0;
	{
		char *test = ft_strdup("test");
		if (test == NULL) {
			printf("malloc error\n");
			printf("%d\n", errno);
			goto skip;
		}
		printf("%s\n", test);
		free(test);
	}
skip:
	errno = 0;
	{
		char *test = strdup("test");
		if (test == NULL) {
			printf("malloc error\n");
			printf("%d\n", errno);
		}
		printf("%s\n", test);
		free(test);
	}
	return 0;
}

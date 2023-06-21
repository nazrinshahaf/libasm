#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

extern char *ft_strdup(const char *s1);

int main()
{
	char *test = ft_strdup("");
	printf("%s\n", test);
	free(test);
	return 0;
}

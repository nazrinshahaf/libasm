#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int ft_strcmp(const char *s1, const char *s2);

int main()
{
	char s1[] = "\0";
	char s2[] = "\0\0test";
	printf("%d\n", ft_strcmp(s1,s2));
	printf("%d\n", strcmp(s1,s2));
	return 0;
}

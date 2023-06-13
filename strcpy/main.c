#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char *ft_strcpy(const char *ft_dst, const char *ft_src);

void test_ft_strcpy()
{
	/* { */
	/* 	char ft_src[] = "stuff"; */
	/* 	char src[] = "stuff"; */
	/*  */
	/* 	char *ft_test = ft_strcpy(malloc(strlen(ft_src) + 1), ft_src); */
	/* 	char *test = strcpy(malloc(strlen(src) + 1), src); */
	/* 	printf("ft_strcpy(malloc) = [%s] | ", ft_test); */
	/* 	printf("strcpy(malloc) = [%s]", test); */
	/* 	printf(" ["); */
	/* 	if (strcmp(ft_test, test) == 0) */
	/* 		printf("✅"); */
	/* 	else */
	/* 		printf("💣"); */
	/* 	printf("] \n"); */
	/* } */
	/* { */
	/* 	char ft_src[] = "stuff"; */
	/* 	char src[] = "stuff"; */
	/* 	char ft_dst[30]; */
	/* 	char dst[30]; */
	/* 	ft_strcpy(ft_dst, ft_src); */
	/* 	printf("ft_src = [%s]\n", ft_src); */
	/* 	printf("ft_dst = [%s]\n", ft_dst); */
	/* } */
	{
		char src[] = "12345";
		char dst[3];
		char dst2[3];
		/* ft_strcpy(dst, src); */
		printf("src b4 = [%s]\n", src);
		ft_strcpy(dst2, src);
		printf("src af = [%s]\n", src);
		printf("dst = [%s]\n", dst);
		printf("dst2 = [%s]\n", dst2);
		/* printf("%s\n", strcpy(src, src)); */
	}
}

int main()
{
	test_ft_strcpy();
	return 0;
}

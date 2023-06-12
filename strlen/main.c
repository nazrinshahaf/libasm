#include <stdio.h>
#include <string.h>

extern size_t ft_strlen(const char *str);

void test_ft_strlen(const char *str)
{
	size_t ft_strlen_res = ft_strlen(str);
	size_t strlen_res = strlen(str);

	printf("_ft_strlen(\"%s\") = %zu | ", str, ft_strlen_res);
	printf("strlen(\"%s\") = %zu", str, strlen_res);

	printf(" [");
	if (ft_strlen_res - strlen_res != 0)
		printf("💣");
	else
		printf("✅");
	printf("] \n");
}

int main()
{
	ft_strlen("zulul");
	/* test_ft_strlen("zulul"); */
	/* test_ft_strlen(""); */
	/* test_ft_strlen("check words with spaces"); */
	/* test_ft_strlen("check words with numbre 917823901723921"); */
}

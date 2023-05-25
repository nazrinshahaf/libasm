#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int main()
{
	printf("%d", (int)ft_strlen("Lmao"));
}

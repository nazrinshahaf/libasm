#include <stddef.h>
#include <stdint.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/_types/_null.h>
#include <unistd.h>
#include <errno.h>
#include "inc/libasm.h"
#include "inc/colours.h"

#define SIZE 10
#define R_SIZE 50

int			cmp(void *a, void *b)
{
	if ((size_t)a == (size_t)b)
		return (0);
	else
		return (1);
}

int			swap_cmp(void *a, void *b)
{
	if (a < b)
		return 0;
	return 1;
}

void	ft_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*a;
	t_list	*b;

	a = *begin_list;
	while (a != NULL)
	{
		b = *begin_list;
		while (b->next != NULL)
		{
			if ((*cmp)(b->data, b->next->data) > 0)
			{
				void	*data;

				data = b->data;
				b->data = b->next->data;
				b->next->data = data;
			}
			b = b->next;
		}
		a = a->next;
	}
}

void		ft_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void*, void*))
{
	t_list		*current;
	t_list		*previous;

	previous = 0;
	current = *begin_list;
	while (current)
	{
		/* printf("a = %d\n", (*(int*)current->data)); */
		/* printf("b = %d\n", (int)data_ref); */
		if ((cmp)((void*)current->data, data_ref) == 0)
		{
			printf("WORKED\n");
			if (previous == 0)
				*begin_list = current->next;
			else
				previous->next = current->next;
			free(current);
		}
		previous = current;
		current = current->next;
	}
}

t_list		*lst_new(void *data)
{
	t_list		*lst;

	lst = (t_list*)malloc(sizeof(t_list));
	lst->next = 0;
	lst->data = data;
	return (lst);
}

void print_list(t_list *begin)
{
	t_list	*temp = begin;

	printf("====================\n");
	printf("size = %d\n", ft_list_size(temp));
	while (temp) {
		printf("%p [%d] -> %p\n", temp, (int)(size_t)temp->data, temp->next);
		temp = temp->next;
	}
	printf("====================\n");
}

void test_ft_write()
{
	printf(BLUE"Testing writing to STDOUT\n"RESET);
	printf("\n");
	{
		char str[] = "some stuff to write";
		ssize_t my_ret;
		ssize_t real_ret;
		int	my_err;
		int	real_err;

		errno = 0;
		printf(" | %zd | my write\n", my_ret = ft_write(STDOUT_FILENO, str, strlen(str)));
		my_err = errno;

		errno = 0;
		printf(" | %zd | real write\n", real_ret = write(STDOUT_FILENO, str, strlen(str)));
		real_err = errno;

		printf("ft_write(STDOUT_FILENO, str, strlen(str)) = [%zd] | ", my_ret);
		printf("write(STDOUT_FILENO, str, strlen(str)) = [%zd]", my_ret);
		printf(" [");
		if (my_ret == real_ret)
			printf("✅");
		else
			printf("💣");
		printf("] \n\n");

		printf("my errno = [%d] | ", my_err);
		printf("real errno = [%d]", real_err);
		printf(" [");
		if (my_ret == real_ret)
			printf("✅");
		else
			printf("💣");
		printf("] \n\n");
	}

	printf(BLUE"Testing writing to invlalid FD\n"RESET);
	printf("\n");
	{
		char str[] = "some stuff to write";
		ssize_t my_ret;
		ssize_t real_ret;
		int	my_err;
		int	real_err;
		
		errno = 0;
		printf(" | %zd | real write\n", my_ret = write(100, str, strlen(str)));
		my_err = errno;

		errno = 0;
		printf(" | %zd | my write\n", real_ret = ft_write(100, str, strlen(str)));
		real_err = errno;

		printf("ft_write(100, str, strlen(str)) = [%zd] | ", my_ret);
		printf("write(100, str, strlen(str)) = [%zd]", my_ret);
		printf(" [");
		if (my_ret == real_ret)
			printf("✅");
		else
			printf("💣");
		printf("] \n\n");

		printf("my errno = [%d] | ", my_err);
		printf("real errno = [%d]", real_err);
		printf(" [");
		if (my_ret == real_ret)
			printf("✅");
		else
			printf("💣");
		printf("] \n\n");
	}
	//write a tester for writing into an actual file
	{
	}
}

void test_ft_strcpy()
{
	printf(BLUE"Testing with malloced data\n"RESET);
	{
		char ft_src[] = "stuff";
		char src[] = "stuff";
	
		char *ft_test = ft_strcpy(malloc(strlen(ft_src) + 1), ft_src);
		char *test = strcpy(malloc(strlen(src) + 1), src);
		printf("ft_strcpy(malloc) = [%s] | ", ft_test);
		printf("strcpy(malloc) = [%s]", test);
		printf(" [");
		if (strcmp(ft_test, test) == 0)
			printf("✅");
		else
			printf("💣");
		printf("] \n\n");
	}
	printf(BLUE"Testing with stack data\n"RESET);
	{
		char ft_src[] = "stuff";
		char src[] = "stuff";
		char ft_dst[30];
		char dst[30];

		ft_strcpy(ft_dst, ft_src);
		strcpy(dst,src);
		printf("ft_src = [%s] | ", ft_src);
		printf("src = [%s]", src);
		printf(" [");
		if (strcmp(ft_src, src) == 0)
			printf("✅");
		else
			printf("💣");
		printf("] \n");

		printf("ft_dst = [%s] | ", ft_dst);
		printf("dst = [%s]", dst);
		printf(" [");
		if (strcmp(ft_dst, dst) == 0)
			printf("✅");
		else
			printf("💣");
		printf("] \n\n");
	}
}

void test_ft_strdup()
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
}

void test_ft_sort()
{
	{
		printf("Testing with random numbers\n");
		t_list	*start = NULL;
		srand(time(NULL));
		for (int i = 0; i < SIZE; i++) {
			int r = rand() % R_SIZE;
			ft_list_push_front(&start, (void*)(size_t)r);
		}
		print_list(start);
		ft_list_sort(&start, &swap_cmp);
		print_list(start);
	}

	{
		printf("Testing with 3-2-1\n");
		t_list	*start = NULL;
		ft_list_push_front(&start, (void*)1);
		ft_list_push_front(&start, (void*)2);
		ft_list_push_front(&start, (void*)3);

		print_list(start);
		ft_list_sort(&start, &swap_cmp);
		print_list(start);
	}
}

void test_ft_strcmp()
{
	printf(BLUE"ft_strcmp(\"\\0\", \"\\0\\0test\")\n"RESET);
	{
		char s1[] = "\0";
		char s2[] = "\0\0test";
		printf("ft_strcmp(s1,s2) == [%d] | ", ft_strcmp(s1,s2));
		printf("strcmp(s1,s2) == [%d]", strcmp(s1,s2));

		printf(" [");
		if (ft_strcmp(s1, s2) != strcmp(s1, s2))
			printf("💣");
		else
			printf("✅");
		printf("] \n\n");
	}

	printf(BLUE"ft_strcmp(\"test123\", \"test\")\n"RESET);
	{
		char s1[] = "test123";
		char s2[] = "test";
		printf("ft_strcmp(s1,s2) == [%d] | ", ft_strcmp(s1,s2));
		printf("strcmp(s1,s2) == [%d]", strcmp(s1,s2));

		printf(" [");
		if (ft_strcmp(s1, s2) != strcmp(s1, s2))
			printf("💣");
		else
			printf("✅");
		printf("] \n\n");
	}

	printf(BLUE"ft_strcmp(\"\", \"1\")\n"RESET);
	{
		char s1[] = "";
		char s2[] = "1";
		printf("ft_strcmp(s1,s2) == [%d] | ", ft_strcmp(s1,s2));
		printf("strcmp(s1,s2) == [%d]", strcmp(s1,s2));

		printf(" [");
		if (ft_strcmp(s1, s2) != strcmp(s1, s2))
			printf("💣");
		else
			printf("✅");
		printf("] \n\n");
	}
}

void test_ft_strlen()
{
#define ARR_SIZE 4
	const char *arr[ARR_SIZE] = {"zulul", "", "check words with spaces", "check words with numbre 917823901723921"};

	for (int i = 0; i < ARR_SIZE; i++)
	{
		printf(BLUE"ft_strlen(%s)\n"RESET, arr[i]);
		size_t ft_strlen_res = ft_strlen(arr[i]);
		size_t strlen_res = strlen(arr[i]);

		printf("_ft_strlen(\"%s\") = %zu | ", arr[i], ft_strlen_res);
		printf("strlen(\"%s\") = %zu", arr[i], strlen_res);

		printf(" [");
		if (ft_strlen_res - strlen_res != 0)
			printf("💣");
		else
			printf("✅");
		printf("] \n\n");
	}
}

void test_function_print(void (*func)(), char *func_name)
{
	printf("==================================================\n");
	printf(CYAN"\t\tTESTING %s\n"RESET, func_name);
	func();
	printf("==================================================\n");
}

int main()
{
	test_function_print(&test_ft_strlen, "ft_strlen");
	test_function_print(&test_ft_strcpy, "ft_strcpy");
	test_function_print(&test_ft_strcmp, "ft_strcmp");
	test_function_print(&test_ft_write, "ft_write");
	/* test_strcpy(); */
	/* test_ft_strdup(); */
	/* test_ft_sort(); */
	return 0;
}

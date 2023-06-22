#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

extern void *ft_list_push_front(t_list **begin_list, void *data);
extern t_list *ft_list_new(void *data);

t_list	*ft_new(void *data)
{
	t_list	*list;

	list = NULL;
	list = malloc(sizeof(t_list));
	if (list)
	{
		list->data = data;
		list->next = NULL;
	}
	return (list);
}

void	ft_push_front(t_list **begin_list, void *data)
{
	t_list	*list;
	if (*begin_list == NULL) // if list is empty
		*begin_list = ft_new(data);
	else	//else create new element and push back
	{
		list = ft_new(data);
		list->next = *begin_list;
		*begin_list = list;
	}
}

void	test_list_new()
{
	errno = 0;
	{
		t_list	*test;
		int		i = 10;

		t_list *start = ft_list_new(&i);
		printf("size of pointer = %zd\n", sizeof(&start));
		printf("addr = %p\n", &start->next);
		if (start->next == NULL)
			printf("NULL\n");
		printf("next data = %p\n", (void*)start->next);
		printf("errno = %d\n", errno);
	}
	printf("==================\n");
	errno = 0;
	{
		t_list	*test;
		int		i = 10;

		t_list *start = ft_new(&i);
		printf("size of pointer = %zd\n", sizeof(&start));
		printf("addr = %p\n", &start->next);
		if (start->next == NULL)
			printf("NULL\n");
		printf("next data = %p\n", (void*)start->next);
		printf("errno = %d\n", errno);
	}
}

int main()
{
	/* test_list_new(); */

	{
		int i = 10;
		int j = 20;
		int k = 30;
		int l = 40;
		/* t_list *start = ft_list_new(&i); */
		t_list *empty = NULL;

		ft_list_push_front(&empty, &i);
	
		ft_list_push_front(&empty, &j);
		ft_list_push_front(&empty, &k);
		ft_list_push_front(&empty, &l);
	
		t_list *il = empty;
		for (int z = 0; z < 5; z++) {
			printf("%d\n", *((int*)il->data));
			if (il->next == NULL)
				break;
			il = il->next;
			printf("%p\n", il);
		}
		printf("%p\n", il);
	}

	/* { */
	/* 	int i = 10; */
	/* 	int j = 20; */
	/* 	int k = 30; */
	/* 	int l = 40; */
	/* 	t_list *start = ft_new(&i); */
	/* 	t_list *empty = NULL; */
	/*  */
	/* 	ft_push_front(&empty, &j); */
	/* 	ft_push_front(&empty, &k); */
	/* 	ft_push_front(&empty, &l); */
	/*  */
	/* 	t_list *il = empty; */
	/* 	for (int z = 0; z < 5; z++) { */
	/* 		printf("%d\n", *((int*)il->data)); */
	/* 		if (il->next == NULL) */
	/* 			break; */
	/* 		il = il->next; */
	/* 		printf("%p\n", il); */
	/* 	} */
	/* 	printf("%p\n", il); */
	/* } */

	return 0;
}

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/_types/_null.h>
#include <unistd.h>
#include <errno.h>

#define SIZE 10
#define R_SIZE 50

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

extern t_list	*ft_list_new(void *data);
extern void		*ft_list_push_front(t_list **begin_list, void *data);
extern int		ft_list_size(t_list *begin);
extern void		*ft_list_remove_if(t_list **begin_list, void *data, int (*cmp)());
extern void		ft_list_sort(t_list **begin_list, int (*cmp)());

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
		printf("%p [%d] -> %p\n", temp, temp->data, temp->next);
		temp = temp->next;
	}
	printf("====================\n");
}

#include <time.h>
#include <stdlib.h>

int main()
{
	{
		printf("Testing with random numbers\n");
		t_list	*start = NULL;
		srand(time(NULL));
		for (int i = 0; i < SIZE; i++) {
			int r = rand() % R_SIZE;
			ft_list_push_front(&start, (void*)r);
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

	return 0;
}

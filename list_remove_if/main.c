#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/_types/_null.h>
#include <unistd.h>
#include <errno.h>

#define SIZE 3

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

extern t_list	*ft_list_new(void *data);
extern void		*ft_list_push_front(t_list **begin_list, void *data);
extern int		ft_list_size(t_list *begin);
extern void		*ft_list_remove_if(t_list **begin_list, void *data, int (*cmp)());

int			cmp(void *a, void *b)
{
	/* printf("a = %d\n", (int)a); */
	/* printf("b = %d\n", (int)b); */
	/* printf("a = %zd\n", (size_t)a); */
	/* printf("b = %zd\n", (size_t)b); */
	if ((size_t)a == (size_t)b)
	{
		/* if ((int)a == (int)b) */
		/* printf("a = %zd\n", (size_t)a); */
		/* printf("b = %zd\n", (size_t)b); */
		/* printf("RETURN 0\n"); */
		return (0);
	}
	else
		return (1);
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

int main()
{
	/* t_list	*start = ft_list_new((void*)arr[0]); */

	/* cmp((void*)10, (void*)(size_t)i); */
	/* cmp(start->data, (void*)(size_t)i); */
	/* printf("%d\n", cmp((void*)(size_t)j, (void*)(size_t)i)); */
	/* ft_remove_if(&start, (void*)(size_t)10, cmp); */
	/* ft_remove_if(&start, (void*)5, &cmp); */
	/* printf("%d\n", (*(int*)start->data)); */
	/* printf("%p\n", start->next); */

	t_list	*start = NULL;
	for (int i = 0; i < SIZE; i++) {
		ft_list_push_front(&start, (void*)i);
	}

	print_list(start);
	for (int i = 0; i < SIZE; i++) {
		ft_list_remove_if(&start, (void*)(size_t)i, cmp);
		print_list(start);
	}
	print_list(start);

	return 0;
}

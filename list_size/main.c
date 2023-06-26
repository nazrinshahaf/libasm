#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/_types/_null.h>
#include <unistd.h>
#include <errno.h>

#define SIZE 10

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

extern void		*ft_list_push_front(t_list **begin_list, void *data);
extern int		ft_list_size(t_list *begin);
extern t_list	*ft_list_new(void *data);


void	ft_push_front(t_list **begin_list, void *data)
{
	t_list	*list;
	if (*begin_list == NULL) // if list is empty
		*begin_list = ft_list_new(data);
	else	//else create new element and push back
	{
		list = ft_list_new(data);
		list->next = *begin_list;
		*begin_list = list;
	}
}

int main()
{
	int arr[SIZE] = {1,2,3,4,5,6,7,8,9,10};
	t_list	*start = ft_list_new(&arr[0]);
	int temp = 3;

	printf("size = %d\n", ft_list_size(start));
	for (int i = 1; i < SIZE; i++) {
		ft_list_push_front(&start, &arr[i]);
		printf("%d\n", (*(int*)start->data));
		printf("size = %d\n", ft_list_size(start));
	}

	t_list *it = start;
	for (int i = 0; i < temp; i++) {
		printf("===============\n");
		printf("curr = %p\n", it);
		printf("[%d]\n", (*(int*)it->data));
		printf("next-> %p\n", it->next);
		printf("===============\n");
		it = it->next;
	}

	return 0;
}

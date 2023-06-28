#ifndef LIBASM_H
#define LIBASM_H

#include <stdio.h>

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

size_t		ft_strlen(const char *str);
char		*ft_strcpy(const char *ft_dst, const char *ft_src);
int			ft_strcmp(const char *s1, const char *s2);
ssize_t 	ft_write(int filedes, const void *buf, size_t nbyte);
ssize_t		ft_read(int fildes, void *buf, size_t nbyte);
char		*ft_strdup(const char *s1);

t_list		*ft_list_new(void *data);
void		*ft_list_push_front(t_list **begin_list, void *data);
int			ft_list_size(t_list *begin);
void		*ft_list_remove_if(t_list **begin_list, void *data, int (*cmp)());
void		ft_list_sort(t_list **begin_list, int (*cmp)());

#endif /* LIBASM_H */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylibc_local.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgriset <kgriset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:41:11 by kgriset           #+#    #+#             */
/*   Updated: 2024/05/14 18:01:18 by kgriset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYLIBC_LOCAL_H
# define MYLIBC_LOCAL_H
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

// mylibc

typedef enum e_signal
{
	ERROR = 0,
	SUCCESS,
}									t_signal;

// functions
char	**ft_mysplit(char const *s, char * set);
int									ft_atoi_safe(char *string, int *status);
int									free_split(char **split);
void								*my_realloc(void *p_origin,
										size_t origin_size,
										size_t requested_size);
int									array_in_place_reverse(int *array,
										size_t end);
int									array_rotate(int *array, size_t amount,
										size_t end);

//  vector implementation suboptimal cause of aving to use my_realloc instead of
//  the real deal
# define VECTOR_INIT_CAPACITY 10

typedef struct s_vector_list
{
	void							**items;
	size_t							capacity;
	size_t							total;
}									t_vector_list;

typedef struct s_vector				t_vector;
struct								s_vector
{
	t_vector_list					vector_list;

	int								(*pf_vec_total)(t_vector *);
	int								(*pf_vec_resize)(t_vector *, size_t);
	int								(*pf_vec_add)(t_vector *, void *);
	int								(*pf_vec_set)(t_vector *, size_t, void *);
	void							*(*pf_vec_get)(t_vector *, size_t);
	int								(*pf_vec_delete)(t_vector *, size_t);
	int								(*pf_vec_free)(t_vector *);
};

void								vector_init(t_vector *v);

int									vector_resize(t_vector *v, size_t capacity);
int									vector_add(t_vector *v, void *item);
int									vector_delete(t_vector *v, size_t index);
int									vector_free(t_vector *v);
void								*vector_get(t_vector *v, size_t index);
int									vector_set(t_vector *v, size_t index,
										void *item);
int									vector_total(t_vector *v);

// Doubly linked lists

typedef struct s_double_link_node	t_double_link_node;
struct								s_double_link_node
{
	t_double_link_node				*next;
	t_double_link_node				*previous;
	void							*data;
};

typedef struct s_double_link_list	t_double_link_list;
struct								s_double_link_list
{
	t_double_link_node				*first_node;
	t_double_link_node				*last_node;

	int								(*pf_insert_after)(t_double_link_list *list,
			t_double_link_node *node,
			t_double_link_node *new_node);
	int								(*pf_insert_before)(t_double_link_list
			*list,
			t_double_link_node *node,
			t_double_link_node *new_node);
	int								(*pf_insert_beginning)(t_double_link_list
			*list,
			t_double_link_node *new_node);
	int								(*pf_insert_end)(t_double_link_list *list,
			t_double_link_node *new_node);
	int								(*pf_delete_node)(t_double_link_list *list,
			t_double_link_node *node);
};

int									insert_after(t_double_link_list *list,
										t_double_link_node *node,
										t_double_link_node *new_node);
int									insert_before(t_double_link_list *list,
										t_double_link_node *node,
										t_double_link_node *new_node);
int									insert_beginning(t_double_link_list *list,
										t_double_link_node *new_node);
int									insert_end(t_double_link_list *list,
										t_double_link_node *new_node);
int									delete_node(t_double_link_list *list,
										t_double_link_node *node);
void								init_list(t_double_link_list *list);
// Circular doubly link lists

typedef struct s_circular_db_ll		t_circular_db_ll;
struct								s_circular_db_ll
{
	t_double_link_node				*first_node;
	t_double_link_node				*last_node;
	size_t							total;

	int								(*pf_insert_after)(t_circular_db_ll
			*cdl_list,
			t_double_link_node *node,
			t_double_link_node *new_node);
	int								(*pf_insert_beginning)(t_circular_db_ll
			*list,
			t_double_link_node *new_node);
	int								(*pf_insert_end)(t_circular_db_ll *list,
			t_double_link_node *new_node);
	int								(*pf_delete_node)(t_circular_db_ll *list,
			t_double_link_node *node);
};

void								cdl_init_list(t_circular_db_ll *list);

int									cdl_insert_after(t_circular_db_ll *cdl_list,
										t_double_link_node *node,
										t_double_link_node *new_node);
int									cdl_insert_beginning(t_circular_db_ll *list,
										t_double_link_node *new_node);
int									cdl_insert_end(t_circular_db_ll *list,
										t_double_link_node *new_node);
int									cdl_delete(t_circular_db_ll *list,
										t_double_link_node *node);
int									cdl_free_list(t_circular_db_ll *list);

////////////////////////////////////////////////////////////////////////////

// libft project
typedef struct s_list
{
	void							*content;
	struct s_list					*next;
}									t_list;

int									ft_atoi(const char *nptr);

void								ft_bzero(void *s, size_t n);

void								*ft_calloc(size_t nmemb, size_t size);

int									ft_isalnum(int c);

int									ft_isalpha(int c);

int									ft_isascii(int c);

int									ft_isdigit(int c);

int									ft_isprint(int c);

void								*ft_memchr(const void *s, int c, size_t n);

int									ft_memcmp(const void *s1, const void *s2,
										size_t n);

void								*ft_memcpy(void *dest, const void *src,
										size_t n);

void								*ft_memmove(void *dest, const void *src,
										size_t n);

void								*ft_memset(void *s, int c, size_t n);

char								**ft_split(char const *s, char c);

char								*ft_strchr(const char *s, int c);

char								*ft_strdup(const char *s);

char								*ft_strjoin(char const *s1, char const *s2);

size_t								ft_strlcat(char *dst, const char *src,
										size_t size);

size_t								ft_strlcpy(char *dst, const char *src,
										size_t dstsize);

size_t								ft_strlen(const char *s);

int									ft_strncmp(const char *s1, const char *s2,
										size_t n);

char								*ft_strnstr(const char *big,
										const char *little, size_t len);

char								*ft_strrchr(const char *s, int c);

char								*ft_strtrim(char const *s1,
										char const *set);

char								*ft_substr(char const *s,
										unsigned int start, size_t len);

int									ft_tolower(int c);

int									ft_toupper(int c);

char								*ft_itoa(int n);

char								*ft_strmapi(char const *s,
										char (*f)(unsigned int, char));

void								ft_striteri(char *s, void (*f)(unsigned int,
											char *));

void								ft_putchar_fd(char c, int fd);

void								ft_putstr_fd(char *s, int fd);

void								ft_putendl_fd(char *s, int fd);

void								ft_putnbr_fd(int n, int fd);

t_list								*ft_lstnew(void *content);

void								ft_lstadd_front(t_list **lst, t_list *new);

int									ft_lstsize(t_list *lst);

t_list								*ft_lstlast(t_list *lst);

void								ft_lstadd_back(t_list **lst, t_list *new);

void								ft_lstdelone(t_list *lst,
										void (*del)(void *));

void								ft_lstclear(t_list **lst,
										void (*del)(void *));

void								ft_lstiter(t_list *lst, void (*f)(void *));

t_list								*ft_lstmap(t_list *lst, void *(*f)(void *),
										void (*del)(void *));
#endif

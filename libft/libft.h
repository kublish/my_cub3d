/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 11:57:52 by zkubli            #+#    #+#             */
/*   Updated: 2020/03/11 09:18:39 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_vector
{
	void			*data;
	size_t			elem_size;
	size_t			count;
	size_t			capacity;
}					t_vector;

typedef struct		s_pq
{
	size_t			count;
	struct s_pq		*left;
	struct s_pq		*right;
	struct s_pq		*parent;
	void			*content;
	size_t			content_size;
}					t_pq;

/*
** printf
*/

int					ft_printf(char *input, ...);

/*
**	Part 1
*/

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *hys, const char *ndle, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
**	Part 2
*/

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
size_t				ft_strlen(const char *s);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_stritr(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s1, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strncpy(char *dst, const char *src, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strcat(char *s1, char *s2);
void				ft_striter(char *s, void (*f)(char*));
char				*ft_strjoin(char const *s1, char const *s2);

/*
** Bonus Functions
*/

t_list				*ft_lstnew(void const *src, size_t sze);
void				ft_lstadd(t_list **alst, t_list *to_add);
void				ft_lstdelone(t_list **alst, void(*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void(*f)(t_list *cnt));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *cnt));
void				ft_lstdel(t_list**alst, void(*del)(void*, size_t));

/*
** My Functions
*/

long				ft_strtol(const char *str, char **endptr, int base);
char				*ft_strndup(const char *str, size_t n);
int					ft_isspace(int c);
int					ft_pow(int base, int power);
int					ft_gcf(int a, int b);
int					ft_lcm(int a, int b);
int					ft_isprime(int a);
int					ft_abs(int a);
int					ft_lstcontain(t_list *lst, void *cntnt, int cntnt_size);
void				ft_lstappend(t_list **lista, t_list *listb);
void				ft_lstprepend(t_list **lista, t_list *listb);
void				ft_lstsort(t_list **root, int (*f) (void *a, void *b));
void				*ft_lstfrontpop(t_list **lista);
int					ft_memswap(void *a, void *b, size_t bytes);
void				ft_remalloc(void **dst, size_t new_size);
int					ft_digitcount(int n);
char				*ft_strpolyjoin(int n, ...);

/*
** Vector
*/

t_vector			*ft_vnew(size_t elem_size);
void				ft_vdoublecap(t_vector *vect);
void				*ft_vget(t_vector *vect, size_t index);
size_t				ft_vadd(t_vector *vect, void *elem);
void				ft_vdel(t_vector *vect, size_t index);
void				ft_vinsert(t_vector *vect, void *elem, size_t index);
void				ft_vswap(t_vector *vect, size_t a, size_t b);
void				ft_vsort(t_vector *vect, int (*f)(void *, void *));

/*
** Priority Queue
*/

t_pq				*ft_pqnew(const void *elem, size_t elem_size);
void				ft_pqpush(t_pq **r, int (*f)(void *a, void *b), t_pq *a);
void				*ft_pqpop(t_pq **root, int (*f)(void *a, void *b));

#endif

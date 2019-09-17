/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 17:54:22 by ishyian           #+#    #+#             */
/*   Updated: 2019/09/16 15:08:01 by ishyian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define ABS(n) 			(((n) < 0) ? ((n) * -1) : (n))
# define DIFF(a,b) 			((a) >= (b) ? (a) - (b) : (b) - (a))
# define GREATEST(a,b)		((a) >= (b) ? (a) : (b))
# define LEAST(a,b) 		((a) <= (b) ? (a) : (b))
# define IS_EVEN(a) 		((a) == ((a) / 2 * 2) ? 1 : 0)
# define UCHAR_MAX_STR 		"255"
# define CHAR_MIN_STR 		"-128"
# define CHAR_MAX_STR 		"127"
# define MB_LEN_MAX_STR 	"6"
# define SHRT_MIN_STR 		"-32768"
# define SHRT_MAX_STR 		"32767"
# define USHRT_MAX_STR 		"65535"
# define INT_MIN_STR 		"-2147483648"
# define INT_MAX_STR 		"2147483647"
# define UINT_MAX_STR 		"4294967295"

# include <string.h>
# include <wchar.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_dllist
{
	void			*content;
	size_t			content_size;
	struct s_dllist	*next;
	struct s_dllist	*prev;
}					t_dllist;

typedef struct		s_quicksort
{
	struct s_dllist	*low;
	struct s_dllist	*high;
	struct s_dllist	*pivot;
	struct s_dllist	*to_swap_low;
	struct s_dllist	*to_swap_high;
	int				(*f)();
}					t_quicksort;

typedef struct		s_quicksort_f_l
{
	struct s_dllist **first;
	struct s_dllist **last;
}					t_quicksort_f_l;

int					get_next_line(const int fd, char **line);
int					get_next_line_endl(const int fd, char **line);
char				*ft_longexpr(const char *a_arg, char op, const char *b_arg);
int					ft_longexprcmp(char *arg_a, char op, char *arg_b);
int					ft_printf(const char *format, ...);
int					ft_fprintf(int fd, const char *format, ...);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
								size_t len);
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
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *str);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_isspace(int c);
int					ft_strlongestwordlen(char const *s);
int					ft_strcountfields(char const *s, char delim);
void				*ft_memdup(const void *src, size_t size);
void				ft_memsdel(void *mem, size_t size);
void				ft_lstaddend(t_list **alst, t_list *new);
t_list				*ft_strsplitlst(char const *s, char c);
size_t				ft_lstlen(t_list const *lst);
void				ft_lstprint(t_list const *lst);
void				ft_lstprint_f(t_list const *lst, void (*f)());
void				ft_printmem(void const *mem, size_t size);
void				ft_printmem_fd(void const *mem, size_t size, int fd);
char				*ft_memjoin(void const *s1, size_t size_s1,
								void const *s2, size_t size_s2);
size_t				ft_strchrcount(const char *s, int c);
size_t				ft_memchrcount(const void *s, int c, size_t n);
void				ft_swap(int *a, int *b);
char				*ft_strchrs(const char *s, const char *chrs);
char				*ft_strrchrs(const char *s, const char *chrs);
char				*ft_strstrchrs(const char *s, const char *chrs);
void				*ft_memrchr(const void *mem, size_t size, int c);
void				*ft_memchrs(const void *mem, const char *chrs, size_t size);
void				*ft_memrchrs(const void *mem, size_t size_mem,
								const char *chrs, size_t size_chrs);
char				*ft_memstrchrs(const void *mem, const char *chrs, size_t n);
size_t				ft_numlen(long long nb);
size_t				ft_numlen_base(long long nb, int base);
size_t				ft_unumlen(unsigned long long nb);
size_t				ft_unumlen_base(unsigned long long nb, int base);
long long			ft_sqrt(long long nb);
long				ft_atol(const char *str);
long long			ft_atoll(const char *str);
char				*ft_ltoa(long n);
char				*ft_lltoa(long long n);
char				*ft_ulltoa(unsigned long long n);
void				*ft_memstr(const void *haystack, const char *needle,
							size_t size);
int					ft_issign(int c);
void				*ft_smalloc(size_t size);
char				*ft_lltoa_base(long long n, int base);
char				*ft_ltoa_base(long n, int base);
char				*ft_itoa_base(int n, int base);
char				*ft_ulltoa_base(unsigned long long n, int base);
char				*ft_ultoa_base(unsigned long n, int base);
char				*ft_uitoa_base(unsigned int n, int base);
int					ft_islower(int c);
int					ft_isupper(int c);
void				ft_strtolower(char *s);
void				ft_strtoupper(char *s);
void				ft_decrement(size_t *nb, size_t decremention);
size_t				ft_wstrlen(const wchar_t *ws);
size_t				ft_unistrlen(const unsigned char *s);
size_t				ft_wstrsumlen(const wchar_t *ws);
size_t				ft_wchrlen(const wchar_t wc);
char				*ft_getbitstr(const void *p, size_t size);
char				*ft_getbitstrr(const void *p, size_t size);
int					ft_atoi_base(const char *str, int base);
long				ft_atol_base(const char *str, int base);
void				ft_sfree(void **ptr);
void				ft_dllstadd(t_dllist **alst, t_dllist *new);
void				ft_dllstaddend(t_dllist **alst, t_dllist *new);
t_dllist			*ft_dllstnew(void const *content, size_t content_size);
void				ft_dllstins(t_dllist *prev, t_dllist *new, t_dllist *next);
void				ft_dllstswap(t_dllist **a, t_dllist **b);
void				ft_dllstdel(t_dllist **alst, void (*del)(void *, size_t));
size_t				ft_dllstlen(t_dllist *list, t_dllist *last);
void				ft_pswap(void **a, void **b);
int					ft_isnum(char *str);
void				ft_quicksort(t_dllist **list, t_dllist **last, int (*f)());
int					ft_quicksort_swap_items(t_quicksort *t_sort,
											t_quicksort_f_l *t_f_l);
void				ft_dllstprint(t_dllist *list, t_dllist *last);
t_dllist			*ft_dllstdup(t_dllist *list, t_dllist *last);
t_dllist			*ft_dllstmiddle(t_dllist *list, t_dllist *last);
int					ft_getlogfilefd(void);
int					ft_getint(char *str);
int					ft_strsplits_count(char **points);
void				ft_strsplits_free(char ***splits);
void				ft_dllstextract(t_dllist *item);

#endif

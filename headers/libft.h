/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:52:49 by shaintha          #+#    #+#             */
/*   Updated: 2024/11/11 12:54:37 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 17
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <fcntl.h>

typedef struct s_list
{
	char			*attr;
	struct s_list	*next;
}					t_list;

bool	ft_isalpha(int c);
bool	ft_isdigit(int c);
bool	ft_isnumber(char *str);
bool	ft_isnumber_n(char *str, size_t n);
bool	ft_isint(char *str);
bool	ft_isalnum(int c);
bool	ft_isascii(int c);
bool	ft_isprint(int c);
bool	ft_isspace(int c);
bool	ft_isspace_str(char *str);
bool	ft_is_same(char *str1, char *str2);
int		ft_toupper(int c);
int		ft_tolower(int c);
size_t	ft_strlen(const char *str);
size_t	ft_strarrlen(char **strarr);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
size_t	ft_strlcat(char *dest, const char *src, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t n);
int		ft_atoi(const char *str);
int		ft_atoi_n(const char *str, size_t n);
void	ft_bzero(void *str, size_t n);
void	*ft_memset(void *str, int c, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
void	*ft_calloc(size_t nmemb, size_t n);
char	*ft_strdup(const char *src);
char	*ft_strdup_until(const char *src, char c);
char	**ft_strarrdup(char **src);
char	**ft_stradd_tostrarr(char **strarr, char *str);
char	**ft_strdel_fromstrarr(char **strarr, int pos);
char	**ft_strreplace_instrarr(char **strarr, char *new_str, int pos);
char	**ft_sort_strarr(char **strarray);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strjoin(char const *str1, char const *str2);
char	*ft_strjoin_gnl(char *str1, char *str2);
char	*ft_strtrim(char const *str1, char const *set);
char	**ft_split(char const *str, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *str, char (*f)(unsigned int, char));
void	ft_striteri(char const *str, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putstrarr_fd(char **strarr, int fd);
void	ft_putendl_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putlst_fd(t_list *lst, int fd);
t_list	*ft_lstnew(char *attr);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list **lst, t_list *node);
void	ft_lstclear(t_list **lst);
void	ft_free(void *ptr);
void	ft_free_strarr(char **strarr);
char	*get_file_content(char *file_name);

#endif
